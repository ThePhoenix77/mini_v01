#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;
	char	*empty_str;

	i = 0;
	if (s == NULL || start >= (unsigned int)ft_strlen(s) || len == 0)
	{
		empty_str = (char *)malloc(1);
		if (empty_str == NULL)
			return (NULL);
		empty_str[0] = '\0';
		return (empty_str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = (char *)malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[len] = '\0';
	return (substring);
}
