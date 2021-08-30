
#include "libft.h"

int		ft_isalnum(int ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)
		|| (ch >= 48 && ch <= 57))
		return (1);
	else
		return (0);
}
