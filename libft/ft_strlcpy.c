#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	const char	*srcp;

	srcsize = ft_strlen(src);
	srcp = src;
	if (dstsize == 0)
		return (srcsize);
	if (dstsize > 0)
	{
		while (--dstsize > 0 && *src)
		{
			*dst++ = *src++;
		}
		*dst = '\0';
	}
	return (srcsize);
}
