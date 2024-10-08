/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:22:15 by eaboudi           #+#    #+#             */
/*   Updated: 2024/08/09 16:36:04 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H


# define Failure false
# define Success true
# define HISTORY_FILE ".shell_history"

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct sigaction t_sigaction;

typedef	struct s_global
{
	char	**env;
	char	*line_input;
}	t_global;

void	initialize_history(void);
void	save_history(void);
void    free_tab(char **tab);
char	*find_path(char **split, char *cmd);
char	*get_path(char *cmd, char **envp);
void	ft_execve(char	*line_input, char **env);
void	handle_execve_error(void);
void	free_tab(char **tab);


#endif