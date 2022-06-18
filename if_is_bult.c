/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:21:49 by asalek            #+#    #+#             */
/*   Updated: 2022/06/04 16:17:33 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in_(char **cmd, t_data *t, char *cmdline)
{
	if (!ft_strcmp(cmd[0], "cd"))
		return (1);
	if (!ft_strcmp(cmd[0], "pwd"))
		return (1);
	if (!ft_strcmp(cmd[0], "exit"))
		return (1);
	if (!ft_strcmp(cmd[0], "echo"))
		return (1);
	if (!ft_strcmp(cmd[0], "env"))
		return (1);
	if (!ft_strcmp(cmd[0], "export"))
		return (1);
	if (!ft_strcmp(cmd[0], "unset"))
		return (1);
	else
		return (0);
}

int	if_is_bult(char *cmd, t_data *t)
{
	char	*path;
	char	**cmd_split;

	path = return_path(t->envp);
	t->split_path = NULL;
	t->i = 0;
	if (t->env_list)
	{
		t->split_path = split_path(path);
		t->i = count_words(path, ':');
	}
	cmd_split = ft_split(cmd, ' ');
	remove_space_quotes(cmd_split);
	if (!cmd || !ft_strncmp(cmd, "", 1))
		return (free_dp(cmd_split), 0);
	while (*cmd == ' ')
		cmd++;
	if (built_in_(cmd_split, t, cmd))
		return (free_dp(cmd_split), 1);
	else if (!strncmp("./", cmd, 2) || !strncmp("/", cmd, 1))
		return (free_dp(cmd_split), 1);
	free_dp(cmd_split);
	return (0);
}
