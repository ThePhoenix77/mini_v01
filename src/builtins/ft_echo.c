/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:11:35 by tboussad          #+#    #+#             */
/*   Updated: 2024/07/26 22:25:08 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_echo(char **args)
{
    int i;
    int new;

    i = 1;
    new = 0;
    while (args[i])
    {
        if (ft_strcmp(args[i], "-n" == 0))
        {
            new = 1;
            continue;
        }
        ft_putstr_fd(args[i], 1);
        ft_putstr_fd(" ", 1);
    }
    if (!new)
        ft_putstr_fd("\n", 1);
    return (0);
}