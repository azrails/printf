
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t f;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		f = 0;
		if (big[i] == little[f])
		{
			while ((big[i + f] == little[f]) && (little[f] != '\0') &&
				(i + f < len))
				f++;
			if (little[f] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
