/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:53:53 by asalek            #+#    #+#             */
/*   Updated: 2022/06/03 15:14:29 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	file_sys_red_2(char *cmd, char **cmd_split, char **split_p, t_data *t)
{
	int	i;

	i = 0;
	if (!cmd || !ft_strncmp(cmd, "", 1))
		return ;
	while (*cmd == ' ')
		cmd++;
	if (!strncmp("./", cmd, 2) || !strncmp("/", cmd, 1))
		execut_cmd_2("", cmd_split, cmd, t);
	else if (cmd_found_2(t->i, split_p, cmd_split) == 0)
		printf("COMMAND NOT FOUND \n");
	execute_path_2(t, split_p, cmd_split, cmd);
}

void	file_sys_red(char *cmd, t_data *t)
{
	char	*path;
	char	**split_p;
	char	**cmd_split;
	int		i;

	path = return_path(t->envp);
	split_p = NULL;
	t->i = 0;
	if (t->env_list)
	{
		split_p = split_path(path);
		t->i = count_words(path, ':');
	}
	cmd_split = ft_split(cmd, ' ');
	i = 1;
	while (cmd_split[i])
	{
		check_quots(cmd_split[i]);
		remove_spaces(cmd_split[i]);
		i++;
	}
	file_sys_red_2(cmd, cmd_split, split_p, t);
}

char	*cmd_found_2(int count, char **split_p, char **cmd)
{
	int				i;
	DIR				*dir;
	struct dirent	*entry;

	i = 0;
	while (i < count)
	{
		dir = opendir(split_p[i]);
		if (dir == NULL)
			return (free_dp(split_p), free_dp(cmd), NULL);
		else
		{
			entry = readdir(dir);
			while (entry != NULL)
			{
				if (ft_strcmp(entry->d_name, cmd[0]) == 0)
					return (closedir(dir), split_p[i]);
				entry = readdir(dir);
			}
		}
		closedir(dir);
		i++;
	}
	g_exit = 127;
	return (free_dp(split_p), free_dp(cmd), NULL);
}
