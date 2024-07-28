/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:22:47 by eaboudi           #+#    #+#             */
/*   Updated: 2024/07/21 16:17:44 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void initialize_history()
{
    using_history();
    read_history(HISTORY_FILE);
}

void save_history()
{
    write_history(HISTORY_FILE);
}