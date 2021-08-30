
#include "../include/ft_printf.h"

int		ft_len(unsigned long dig, t_flag *flags)
{
	int		lenhex;

	lenhex = 0;
	if (dig == 0 && flags->dot != 0)
		return (1);
	else if (dig == 0 && flags->dot == 0)
		return (0);
	while (dig)
	{
		dig /= 10;
		lenhex++;
	}
	return (lenhex);
}

void	ft_printn(t_flag *flags, int dot, int *tmp, int i)
{
	while (dot > 0)
	{
		write(1, "0", 1);
		flags->count++;
		dot--;
	}
	if (flags->minx == -2147483648)
	{
		ft_putstr_fd("2147483648", 1);
		flags->count += 10;
		return ;
	}
	while (i >= 0)
	{
		if (flags->minx == 0 && flags->dot == 0)
			break ;
		ft_putchar(tmp[i] + '0');
		flags->count++;
		i--;
	}
}

int		ft_proc(int *pos, t_flag *flags, int *dot)
{
	int		len;

	*dot = 0;
	*pos = 0;
	flags->minx = flags->num;
	if (flags->num < 0)
	{
		flags->num = -(flags->num);
		*pos = 1;
	}
	len = ft_len(flags->num, flags);
	if (flags->dot > len)
	{
		*dot = flags->dot - len;
		len = flags->dot;
	}
	if (flags->dot >= 0)
		flags->zero = 0;
	if (*pos == 1)
		len += 1;
	if (flags->minx == -2147483648)
		len = 11;
	return (len);
}

int		ft_procnum(t_flag *flags, int *tmp, int pos)
{
	int		i;

	i = 0;
	if (flags->num / 10 != 0)
	{
		while (flags->num / 10 != 0)
		{
			tmp[i] = flags->num % 10;
			flags->num = flags->num / 10;
			i++;
		}
		tmp[i] = flags->num;
	}
	else
		tmp[i] = flags->num;
	if (pos == 1)
	{
		write(1, "-", 1);
		flags->count++;
	}
	return (i);
}

void	ft_printnum(t_flag *flags, int num)
{
	int		*tmp;
	int		len;
	int		dot;
	int		pos;
	int		i;

	if (!(tmp = malloc(sizeof(int) * 10)))
	{
		flags->count = -1;
		return ;
	}
	flags->num = num;
	len = ft_proc(&pos, flags, &dot);
	if (flags->width != 0 && flags->minus == 0 && flags->width > len
	&& flags->zero == 0)
		ft_printwidth(flags, 'x', (flags->width - len));
	i = ft_procnum(flags, tmp, pos);
	if (flags->width != 0 && flags->minus == 0 && flags->width > len
	&& flags->zero == 1)
		ft_printwidth(flags, 'x', (flags->width - len));
	ft_printn(flags, dot, tmp, i);
	if (flags->width != 0 && flags->minus == 1 && flags->width > len)
		ft_printwidth(flags, 'x', (flags->width - len));
	free(tmp);
}
