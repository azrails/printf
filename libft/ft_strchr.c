
#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*s1;
	int		i;

	s1 = (char *)str;
	i = 0;
	while (s1[i] != 0)
	{
		if (s1[i] == ch)
		{
			return (&s1[i]);
		}
		i++;
	}
	if (s1[i] == '\0' && ch == '\0')
		return (&s1[i]);
	return (NULL);
}
