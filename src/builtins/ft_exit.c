/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:28:00 by tboussad          #+#    #+#             */
/*   Updated: 2024/07/30 13:57:41 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int main(int argc, char **args, char **env)
{
    (void)argc;
    int status = 0;

    if (args[1] != NULL)
        status = ft_atoi(args[1]);
    ft_execve(ft_strjoin("exit ", ft_itoa(status)), env);
}