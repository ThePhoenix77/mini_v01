#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s == c)
			word = 0;
		else if (!word)
		{
			word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*cpw(char const *s, char c)
{
	int		wlen;
	char	*word;
	int		i;

	wlen = 0;
	i = 0;
	while (s[wlen] && s[wlen] != c)
		wlen++;
	word = (char *)malloc(wlen + 1);
	if (word == NULL)
		return (NULL);
	while (i < wlen)
	{
		word[i] = s[i];
		i++;
	}
	word[wlen] = '\0';
	return (word);
}

static char	**ft_free(char **res, int n)
{
	while (n > 0)
		free(res[--n]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		w_count;

	if (!s)
		return (NULL);
	w_count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!res)
		return (NULL);
	res[w_count] = NULL;

	i = 0;
	while (i < w_count)
	{
		while (*s && *s == c)
			s++;
		res[i] = cpw(s, c);
		if (!res[i])
			return (ft_free(res, i));
		while (*s && *s != c)
			s++;

		i++;
	}

	return (res);
}
