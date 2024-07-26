/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token_Recognition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaboudi <eaboudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:42:40 by eaboudi           #+#    #+#             */
/*   Updated: 2024/07/20 14:46:32 by eaboudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	check_ipute(char *line_input)
{
	int	i;

	i = 0;
	if (line_input[0] == '#')
		return (Failure);
}
