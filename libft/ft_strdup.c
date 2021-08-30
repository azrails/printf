
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s1;
	int		i;

	i = ft_strlen(str);
	if (!(s1 = malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
