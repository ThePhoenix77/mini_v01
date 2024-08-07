/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:34:12 by tboussad          #+#    #+#             */
/*   Updated: 2024/08/07 21:36:19 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_export(char *args[])
{
    int i;
    char *var;
    char *value;

    i = 1;
    while (args[i] != NULL)
    {
        var = strtok(args[i], "=");
        if (var == NULL) {
            fprintf(stderr, "invalid syntax: %s\n", args[i]);
            continue;
        }
        value = strtok(NULL, "");
        if (value == NULL) {
            fprintf(stderr, "missing value for variable: %s\n", var);
            continue;
        }
        setenv(var, value, 1);
        i++;
    }
}
