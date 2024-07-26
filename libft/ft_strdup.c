#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*copy;
	char	*cp;

	size = ft_strlen(s1);
	copy = (char *)malloc(size + 1);
	if (copy == NULL)
		return (NULL);
	cp = copy;
	while (*s1)
	{
		*copy++ = *s1++;
	}
	*copy = '\0';
	return (cp);
}
