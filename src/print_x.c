/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:26:39 by wsallei           #+#    #+#             */
/*   Updated: 2020/07/30 13:39:28 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printx(int num, char ud)
{
	if (num == 10)
		(ud == 'x') ? ft_putchar('a') : ft_putchar('A');
	else if (num == 11)
		(ud == 'x') ? ft_putchar('b') : ft_putchar('B');
	else if (num == 12)
		(ud == 'x') ? ft_putchar('c') : ft_putchar('C');
	else if (num == 13)
		(ud == 'x') ? ft_putchar('d') : ft_putchar('D');
	else if (num == 14)
		(ud == 'x') ? ft_putchar('e') : ft_putchar('E');
	else if (num == 15)
		(ud == 'x') ? ft_putchar('f') : ft_putchar('F');
	else
		ft_putchar(num + '0');
}

int		ft_procxnum(t_flag *flags, int *tmp)
{
	int i;

	i = 0;
	while (flags->num / 16 != 0)
	{
		tmp[i] = flags->num % 16;
		flags->num = flags->num / 16;
		i++;
	}
	tmp[i] = flags->num;
	return (i);
}

int		ft_hproc(t_flag *flags, int *dot)
{
	int len;

	*dot = 0;
	len = ft_lenhex(flags->num, flags);
	if (flags->dot > len)
	{
		*dot = flags->dot - len;
		len = flags->dot;
	}
	if (flags->dot != -1)
		flags->zero = 0;
	return (len);
}

void	ft_printxn(t_flag *flags, int dot, int *tmp, int i)
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
		ft_printx(tmp[i], flags->ud);
		flags->count++;
		i--;
	}
}

void	ft_printhex(t_flag *flags, unsigned int num, char ud)
{
	int		*tmp;
	int		i;
	int		len;
	int		dot;

	if (!(tmp = malloc(sizeof(int) * 20)))
	{
		flags->count = -1;
		return ;
	}
	flags->num = num;
	flags->ud = ud;
	len = ft_hproc(flags, &dot);
	if (flags->width != 0 && flags->minus == 0 && flags->width > len
	&& flags->zero == 0)
		ft_printwidth(flags, 'x', (flags->width - len));
	i = ft_procxnum(flags, tmp);
	if (flags->width != 0 && flags->minus == 0 && flags->width > len
	&& flags->zero == 1)
		ft_printwidth(flags, 'x', (flags->width - len));
	ft_printxn(flags, dot, tmp, i);
	if (flags->width != 0 && flags->minus == 1 && flags->width > len)
		ft_printwidth(flags, 'x', (flags->width - len));
	free(tmp);
}
