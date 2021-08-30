
#include "../include/ft_printf.h"

void	ft_printc(t_flag *flags, unsigned char c)
{
	if (flags->width != 0 && flags->minus == 0 && flags->width > 1)
		ft_printwidth(flags, 'c', (flags->width - 1));
	write(1, &c, 1);
	flags->count++;
	if (flags->width != 0 && flags->minus == 1 && flags->width > 1)
		ft_printwidth(flags, 'c', (flags->width - 1));
}
