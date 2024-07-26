#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*joined_str;

	i = 0;
	j = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	joined_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined_str == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		joined_str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		joined_str[i] = s2[j];
		i++;
		j++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}
