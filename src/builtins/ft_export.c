/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:34:12 by tboussad          #+#    #+#             */
/*   Updated: 2024/08/09 08:55:51 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void t(){
//     system("leaks a.out");
// }

int ft_strlen2(char *s)
{
    int i = 0;
    while(s[i]) i++;
    return (i);
}
char	*ft_strdup2(char *s1)
{
	int		size;
	char	*copy;
	char	*cp;

	size = ft_strlen2(s1);
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

char	*ft_strchr2(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char *ft_strsep(char **stringp, char *delim)
{
    char *start = *stringp;
    char *end;

    if (*stringp == NULL)
        return NULL;

    end = ft_strchr2(*stringp, *delim);
    if (end != NULL)
    {
        *end = '\0';
        *stringp = end + 1;
    }
    else 
        *stringp = NULL;

    return start;
}

void ft_export(char *args[])
{
    // atexit(t);
    int i;
    char *var;
    char *value;
    char *copy;

    i = 1;
    while (args[i] != NULL)
    {
        copy = ft_strdup2(args[i]);
        if (copy == NULL) {
            printf("strdup failed\n");
            exit(1);
        }
        var = ft_strsep(&copy, "=");
        if (var == NULL) {
            printf("invalid syntax: %s\n", args[i]);
            free(copy);
            continue;
        }
        value = copy; // strsep modifies copy, so value points to the rest
        if (*value == '\0')
            printf("missing value for variable: %s\n", var);
        else
            setenv(var, value, 1);
        // free(copy);
        i++;
    }
}

int main(int argc, char *argv[]) {
    char *args1[] = {"VAR1=value1", "VAR2=value2", NULL};
    char *args2[] = {"VAR3=", NULL}; // Missing value
    char *args3[] = {"=value4", NULL}; // Missing variable

    // ft_export(argv);
    ft_export(args1);
    printf("VAR1: %s\n", getenv("VAR1"));
    printf("VAR2: %s\n", getenv("VAR2"));

    ft_export(args2);
    printf("VAR3: %s\n", getenv("VAR3"));

    ft_export(args3);

    return 0;
}