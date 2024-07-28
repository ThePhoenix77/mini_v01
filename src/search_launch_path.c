/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_launch_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:29:17 by tboussad          #+#    #+#             */
/*   Updated: 2024/07/21 16:23:28 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//find cmd path from PATH in env
char	*find_path(char **split, char *cmd)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	while (split[i])
	{
		path = ft_strjoin(split[i], "/");
		if (!path)
			return (NULL);
		tmp = path;
		path = ft_strjoin(tmp, cmd);
		if (!path)
			return (NULL);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_tab(split);
			return (path);
		}
		free(path);
		i++;
	}
	free_tab(split);
	return (NULL);
}

//get the final path of the cmd entered
char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**split;

	i = 0;
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);
			split = ft_split(path, ':');
			free(path);
			path = find_path(split, cmd);
			if (path)
				return (path);
		}
		i++;
	}
	return (NULL);
}

//free tab
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}