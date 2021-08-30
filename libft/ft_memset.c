
#include "libft.h"

void		*ft_memset(void *destination, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = destination;
	i = 0;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (destination);
}
