
#include "../include/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_zstr(char **str, t_flag *flags)
{
	if (!(*str))
		*str = "(null)";
}

void	ft_printstr(t_flag *flags, char *str)
{
	int		lenwidth;
	int		i;
	int		tmp;

	i = 0;
	ft_zstr(&str, flags);
	lenwidth = ft_strlen(str);
	if (flags->dot > -1 && flags->dot < lenwidth)
		lenwidth = flags->dot;
	tmp = lenwidth;
	if (flags->width != 0 && flags->minus == 0 && flags->width > lenwidth)
		ft_printwidth(flags, 's', (flags->width - lenwidth));
	while (str[i] != '\0' && (tmp-- > 0))
	{
		ft_putchar(str[i]);
		flags->count++;
		i++;
	}
	if (flags->width != 0 && flags->minus == 1 && flags->width > lenwidth)
		ft_printwidth(flags, 's', (flags->width - lenwidth));
}
