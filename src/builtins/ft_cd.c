/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:38:11 by tboussad          #+#    #+#             */
/*   Updated: 2024/08/07 21:17:55 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// typedef struct
// {
// 	char				*key;
// 	char				*value;
// 	struct env_elmt	*next;
// 	struct env_elmt	*prev;
// }	env_elmt;

// typedef struct
// {
// 	env_elmt			*head;
// 	char				**env;
// 	int					size;
// }	t_env;

// void	set_dir(t_env *ev, char *cwd, char *owd)
// {
// 	env_elmt	*element;

// 	element = search_elment(ev, "PWD");
// 	if (!element)
// 		return ;
// 	element->value = ft_strdup(cwd);
// 	element = search_elment(ev, "OLDPWD");
// 	if (!element)
// 		return ;
// 	element->value = ft_strdup(owd);
// }

void set_dir(char **env, const char *cwd, const char *owd) {
    setenv("PWD", cwd, 1);
    setenv("OLDPWD", owd, 1);
}

int ft_cd(char **args, char **env) {
    char cwd[1024];
    char owd[1024];

    getcwd(owd, sizeof(owd));

    if (!args[1])
    {
        const char *home = getenv("HOME");
        if (chdir(home) != 0) {
            perror("cd");
            return 1;
        }
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("cd");
            return 1;
        }
    }
    getcwd(cwd, sizeof(cwd));
    set_dir(env, cwd, owd);
    return 0;
}

int main(int argc, char *argv[], char *envp[]) {
    char *args1[] = {"cd", NULL};       // Test with no arguments (should go to HOME)
    char *args2[] = {"cd", "..", NULL}; // Test with relative path
    char *args3[] = {"cd", "/", NULL};  // Test with absolute path

    // Display initial PWD and OLDPWD
    printf("Initial PWD: %s\n", getenv("PWD"));
    printf("Initial OLDPWD: %s\n\n", getenv("OLDPWD"));

    // Test cd with no arguments
    printf("Running 'cd' with no arguments...\n");
    ft_cd(args1, envp);
    printf("New PWD: %s\n", getenv("PWD"));
    printf("New OLDPWD: %s\n\n", getenv("OLDPWD"));

    // Test cd with a relative path
    printf("Running 'cd ..'...\n");
    ft_cd(args2, envp);
    printf("New PWD: %s\n", getenv("PWD"));
    printf("New OLDPWD: %s\n\n", getenv("OLDPWD"));

    // Test cd with an absolute path
    printf("Running 'cd /'...\n");
    ft_cd(args3, envp);
    printf("New PWD: %s\n", getenv("PWD"));
    printf("New OLDPWD: %s\n\n", getenv("OLDPWD"));

    ft_cd(args2, envp);

    return 0;
}