
#include "../include/ft_printf.h"

int		ft_preparser(va_list aptr, char *formstr)
{
	int		count;
	int		i;
	t_flag	*flags;

	count = 0;
	i = 0;
	while (formstr[i] && count != -1)
	{
		if (formstr[i] != '%')
		{
			ft_putchar(formstr[i]);
			count++;
		}
		else if (formstr[i] == '%' && formstr[i + 1])
		{
			i++;
			if (!(flags = malloc(sizeof(t_flag))))
				return (-1);
			i = ft_parser(formstr, flags, i, aptr);
			count += flags->count;
			free(flags);
		}
		i++;
	}
	return (count);
}

int		ft_printf(const char *form, ...)
{
	int		count;
	char	*formstr;
	va_list	aptr;

	count = 0;
	if (!(*form) || !(form))
		return (count);
	formstr = ft_strdup(form);
	va_start(aptr, form);
	count = ft_preparser(aptr, formstr);
	va_end(aptr);
	free(formstr);
	return (count);
}
