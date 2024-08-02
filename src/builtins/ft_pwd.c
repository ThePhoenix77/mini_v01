/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:24:46 by tboussad          #+#    #+#             */
/*   Updated: 2024/08/02 14:31:04 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_pwd()
{
    // if (argc > 1 && args[1][1] != 'L' && args[1][1] != 'P')
    // {
    //     printf("bash: pwd: -%c: invalid option\n", args[1][1]);
    //     return (-1);
    // }
    char *cwd;

    cwd = getcwd(NULL, 0);
    if (cwd == NULL)
    {
        perror("getcwd");
        return (-1);        //failure exit status code
    }
    printf("%s\n", cwd);
    free(cwd);
    return 0;               //success exit status code
}

// int main()
// {
//     ft_pwd();
// }