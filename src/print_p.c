/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:32:25 by wsallei           #+#    #+#             */
/*   Updated: 2020/07/26 16:32:27 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_pproc(unsigned long int *dig, t_flag *flags, int *dot)
{
	int len;

	*dot = 0;
	if (*dig == 0)
	{
		if (flags->dot == 0)
		{
			flags->ptr = "0x";
			len = 2;
		}
		else
		{
			flags->ptr = "0x0";
			len = 3;
		}
		flags->minx = 1;
	}
	else
		len = ft_lenhex(*dig, flags);
	if (flags->dot > len && !flags->ptr)
	{
		*dot = flags->dot - len;
		len = flags->dot;
	}
	return (len);
}

int		ft_procpnum(unsigned long int *dig, int *tmp)
{
	int i;

	i = 0;
	while (*dig / 16 != 0)
	{
		tmp[i] = *dig % 16;
		*dig = *dig / 16;
		i++;
	}
	tmp[i] = *dig;
	return (i);
}

void	ft_printp(t_flag *flags, int dot, int *tmp, int i)
{
	if (flags->ptr == NULL)
	{
		write(1, "0", 1);
		write(1, "x", 1);
		flags->count += 2;
		while (dot-- > 0)
		{
			write(1, "0", 1);
			flags->count++;
		}
		while (i >= 0)
		{
			ft_printx(tmp[i], 'x');
			flags->count++;
			i--;
		}
	}
	else
	{
		ft_putstr_fd(flags->ptr, 1);
		flags->count += ft_strlen(flags->ptr);
	}
}

void	ft_printptr(t_flag *flags, unsigned long int dig, char ud)
{
	int *tmp;
	int i;
	int len;
	int dot;

	if (!(tmp = malloc(sizeof(int) * 20)))
		return ;
	len = ft_pproc(&dig, flags, &dot);
	if (flags->width != 0 && flags->minus == 0 &&
	flags->width > len && flags->minx == 0)
		ft_printwidth(flags, 'p', (flags->width - len));
	else if (flags->width != 0 && flags->minus == 0
	&& flags->width > len && flags->minx == 1)
		ft_printwidth(flags, 'p', (flags->width - len));
	i = ft_procpnum(&dig, tmp);
	ft_printp(flags, dot, tmp, i);
	if (flags->width != 0 && flags->minus == 1 && flags->width > len
	&& flags->minx == 0)
		ft_printwidth(flags, 'p', (flags->width - len));
	else if (flags->width != 0 && flags->minus == 1 && flags->width > len
	&& flags->minx == 1)
		ft_printwidth(flags, 'p', (flags->width - len));
	free(tmp);
}
