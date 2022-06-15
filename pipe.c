/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:18:34 by asalek            #+#    #+#             */
/*   Updated: 2022/05/19 20:28:11 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_not_found(int i)
{
	printf("COMMAND NOT FOUND\n");
	g_exit = 127;
	if (i == 0)
		exit(0);
}

int	count(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

void	execute_path(t_data *t, char **split_p, char **cmd_split, char *cmd)
{
	char	*full_path;

	full_path = cmd_found(t->i, split_p, cmd_split);
	full_path = concatenate_string(full_path, "/");
	execut_cmd(full_path, cmd_split, cmd, t);
	free_dp(split_p);
}
