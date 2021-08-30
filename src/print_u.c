
#include "../include/ft_printf.h"

void	ft_printun(t_flag *flags, int dot, int *tmp, int i)
{
	while (dot > 0)
	{
		write(1, "0", 1);
		flags->count++;
		dot--;
	}
	while (i >= 0)
	{
		if (flags->num == 0 && flags->dot == 0)
			break ;
		ft_putchar(tmp[i] + '0');
		flags->count++;
		i--;
	}
}

int		ft_uproc(t_flag *flags, int *dot)
{
	int len;

	*dot = 0;
	len = ft_len(flags->num, flags);
	if (flags->dot > len)
	{
		*dot = flags->dot - len;
		len = flags->dot;
	}
	if (flags->dot != -1)
		flags->zero = 0;
	return (len);
}

int		ft_uprocnum(t_flag *flags, int *tmp)
{
	int i;

	i = 0;
	while (flags->num / 10 != 0)
	{
		tmp[i] = flags->num % 10;
		flags->num = flags->num / 10;
		i++;
	}
	tmp[i] = flags->num;
	return (i);
}

void	ft_printunum(t_flag *flags, unsigned int num)
{
	int *tmp;
	int i;
	int len;
	int dot;

	if (!(tmp = malloc(sizeof(int) * 20)))
	{
		flags->count = -1;
		return ;
	}
	flags->num = num;
	len = ft_uproc(flags, &dot);
	if (flags->width != 0 && flags->minus == 0 && flags->width > len
	&& flags->zero == 0)
		ft_printwidth(flags, 'x', (flags->width - len));
	i = ft_uprocnum(flags, tmp);
	if (flags->width != 0 && flags->minus == 0 && flags->width > len
	&& flags->zero == 1)
		ft_printwidth(flags, 'x', (flags->width - len));
	ft_printun(flags, dot, tmp, i);
	if (flags->width != 0 && flags->minus == 1 && flags->width > len)
		ft_printwidth(flags, 'x', (flags->width - len));
	free(tmp);
}
