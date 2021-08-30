
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;
	int		g;

	if (!s || !f)
		return (NULL);
	i = 0;
	g = ft_strlen((char *)s);
	if (!(res = malloc(sizeof(*res) * (g + 1))))
		return (NULL);
	while (i < g)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
