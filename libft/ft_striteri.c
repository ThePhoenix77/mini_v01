#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t			len;
	unsigned int	i;

	i = 0;
	if ((s == NULL) || (f == NULL))
		return;
	len = ft_strlen(s);
	if ((!s) || (!f))
		return;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
