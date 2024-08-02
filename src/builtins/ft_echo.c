/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:11:35 by tboussad          #+#    #+#             */
/*   Updated: 2024/07/30 13:32:41 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int ft_echo(int argc, char **args)
{
    int i;
    int newline_flag;

    i = 1;
    newline_flag = 0;
    if (ft_strncmp(args[1], "-n", 2) == 0)
    {
        newline_flag = 1;
        i++;
    }
    while (args[i])
    {
        printf("%s", args[i]);
        ft_putstr_fd(args[i], 1);
        if (i < argc - 1)
            printf(" ");
        i++;
    }
    if (newline_flag != 1)
        printf("\n");
    return (0);
}
