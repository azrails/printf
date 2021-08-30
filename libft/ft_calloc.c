
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	i;
	char	*str;

	i = num * size;
	if (!(str = malloc(i)))
		return (NULL);
	else
		return (ft_memset(str, 0, i));
}
