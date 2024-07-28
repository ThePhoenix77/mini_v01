/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:24:46 by tboussad          #+#    #+#             */
/*   Updated: 2024/07/26 22:26:55 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_pwd(char **args)
{
    char *cwd;

    cwd = getcwd(NULL, 0);
    if (cwd == NULL)
    {
        perror("getcwd");
        return 1;
    }
    ft_putstr_fd(cwd, 1);
    ft_putstr_fd("\n", 1);
    free(cwd);
    return 0;
}