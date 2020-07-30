/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 23:16:21 by wsallei           #+#    #+#             */
/*   Updated: 2020/07/26 23:16:23 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_parsstar(va_list aptr, t_flag *flags)
{
	int		tmp;

	tmp = va_arg(aptr, int);
	if (tmp < 0)
	{
		tmp *= -1;
		flags->zero = 0;
		flags->minus = 1;
	}
	flags->star = 1;
	return (tmp);
}

int		ft_parswidth(t_flag *flags, char *formstr, int i)
{
	int		tmp;

	tmp = 0;
	while (formstr[i] >= '0' && formstr[i] <= '9')
	{
		tmp *= 10;
		tmp += formstr[i] - '0';
		i++;
	}
	if (flags->star == 1)
		return (i);
	flags->width = tmp;
	return (i);
}

int		ft_parsdot(t_flag *flags, char *formstr, int i, va_list aptr)
{
	int		tmp;

	tmp = 0;
	if (formstr[i] == '*')
	{
		flags->dot = va_arg(aptr, int);
		i++;
	}
	else
	{
		while (formstr[i] >= '0' && formstr[i] <= '9')
		{
			tmp *= 10;
			tmp += formstr[i] - '0';
			i++;
		}
		flags->dot = tmp;
	}
	return (i);
}

void	ft_format(va_list aptr, char *formstr, t_flag *flags, int i)
{
	if (formstr[i] == 's')
		ft_printstr(flags, va_arg(aptr, char *));
	else if (formstr[i] == 'c')
		ft_printc(flags, va_arg(aptr, int));
	else if (formstr[i] == 'p')
		ft_printptr(flags, va_arg(aptr, unsigned long int), 'x');
	else if (formstr[i] == 'd')
		ft_printnum(flags, va_arg(aptr, int));
	else if (formstr[i] == 'i')
		ft_printnum(flags, va_arg(aptr, int));
	else if (formstr[i] == 'u')
		ft_printunum(flags, va_arg(aptr, unsigned int));
	else if (formstr[i] == 'x')
		ft_printhex(flags, va_arg(aptr, unsigned int), 'x');
	else if (formstr[i] == 'X')
		ft_printhex(flags, va_arg(aptr, unsigned int), 'X');
	else if (formstr[i] == '%')
		ft_printproc(flags, '%');
}

int		ft_parser(char *formstr, t_flag *flags, int i, va_list aptr)
{
	int tmp;

	tmp = i;
	ft_init(flags);
	while (formstr[i] && !(ft_is_format(formstr[i])))
	{
		if (formstr[i] == ' ' && tmp == i)
			write(1, " ", 1);
		if (formstr[i] == '0' && flags->minus == 0 && flags->width == 0)
			flags->zero = 1;
		if (formstr[i] == '-')
			flags->minus = 1;
		if (formstr[i] == '*' && flags->width == 0)
			flags->width = ft_parsstar(aptr, flags);
		if (formstr[i] >= '1' && formstr[i] <= '9')
			i = ft_parswidth(flags, formstr, i);
		if (formstr[i] == '.')
			i = ft_parsdot(flags, formstr, ++i, aptr);
		if (ft_is_format(formstr[i]))
			break ;
		i++;
	}
	ft_format(aptr, formstr, flags, i);
	return (i);
}
