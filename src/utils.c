
#include "../include/ft_printf.h"

void	ft_init(t_flag *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = -1;
	flags->star = 0;
	flags->width = 0;
	flags->count = 0;
	flags->num = 0;
	flags->minx = 0;
	flags->ptr = NULL;
}

int		ft_is_format(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_lenhex(unsigned int dig, t_flag *flags)
{
	int		lenhex;

	lenhex = 0;
	if (dig == 0 && flags->dot != 0)
		return (1);
	else if (dig == 0 && flags->dot == 0)
		return (0);
	while (dig)
	{
		dig /= 16;
		lenhex++;
	}
	return (lenhex);
}

void	ft_printwidth(t_flag *flags, char format, int lenwidth)
{
	int		i;
	char	c;

	c = ' ';
	i = 0;
	if (format == 's' || format == 'p' || format == 'c')
	{
		while (i++ < lenwidth)
		{
			write(1, &c, 1);
			flags->count++;
		}
	}
	else if (format == 'x' || format == '%')
	{
		if (flags->zero == 1 && flags->minus == 0 && flags->dot < 0)
			c = '0';
		while (i++ < lenwidth)
		{
			write(1, &c, 1);
			flags->count++;
		}
	}
}

void	ft_printproc(t_flag *flags, unsigned char c)
{
	if (flags->width != 0 && flags->minus == 0 && flags->width > 1)
		ft_printwidth(flags, '%', (flags->width - 1));
	write(1, &c, 1);
	flags->count++;
	if (flags->width != 0 && flags->minus == 1 && flags->width > 1)
		ft_printwidth(flags, '%', (flags->width - 1));
}
