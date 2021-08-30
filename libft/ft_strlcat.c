
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dstlen;
	size_t i;
	size_t len;

	dstlen = 0;
	i = 0;
	len = ft_strlen(src);
	while (*dest)
	{
		dstlen++;
		dest++;
	}
	if (size <= dstlen)
		return (size + len);
	len += dstlen;
	while ((i < size - dstlen - 1) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
