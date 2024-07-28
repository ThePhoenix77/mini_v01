/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:06:33 by eaboudi           #+#    #+#             */
/*   Updated: 2024/07/23 09:49:04 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void check_leaks()
{
	system("minishell leaks");
}

//custom execve
void	ft_execve(char *cmd, char **env)
{
	char	**split;

	split = ft_split(cmd, ' ');
	if (!split)
		return ;
	cmd = get_path(split[0], env);
	if (!cmd)
	{
		ft_putstr_fd("erreur: commad not found !\n", 2);
		free_tab(split);
		exit(127);
	}
	else
	{
		execve(cmd, split, env);
		free_tab(split);
		free(cmd);
		handle_execve_error();	//to check for usage right in subject (function below)
	}
}

//handle_execve_error
void	handle_execve_error(void)
{
	if (errno == ENOENT)
	{
		ft_putstr_fd("erreur: no such file or directory !\n", 2);
		// exit(127);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("erreur: permission denied !\n", 2);
		// exit(126);
	}
}

//execve in each child process
void	sub_execv(t_global	*global, int pid)
{
	if (pid == 0) {
            ft_execve(global->line_input, global->env);
            exit(EXIT_FAILURE);
        }
		else if (pid > 0)
            wait(NULL);
        else
		{
            perror("fork");
            exit(EXIT_FAILURE);
        }	
}

//read input from terminal
void	get_input(t_global	*global)
{
	pid_t child_exec;

	global->line_input = NULL;
	initialize_history();
	while (1)
	{
		global->line_input = readline("minishell-1.0$ ");
		if (global->line_input == NULL)
			break ;

		if (global->line_input != NULL)
			add_history(global->line_input);
		if (global->line_input[0] == '#')
			continue;
		//creating child and executing
		child_exec = fork();
		sub_execv(global, child_exec);
		//add cmd to history
		if (global->line_input[0] != '\0')
			add_history(global->line_input);
	}
}

int main(int argc, char **argv, char	**env)
{
	// atexit(check_leaks);
	if (argc != 1)
		return (printf("Wrong number of arguments\n"));
	t_global	global;

	global.env = env;
	get_input(&global);
	save_history();
	return (0);
}