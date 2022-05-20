/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:07:44 by asalek            #+#    #+#             */
/*   Updated: 2022/05/20 21:10:54 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_found(int count, char **split_p, char *cmd)
{
	int				i;
	DIR				*dir;
	struct dirent	*entry;

	i = 0;
	while (i < count)
	{
		dir = opendir(split_p[i]);
		if (dir == NULL)
			return (NULL);
		else
		{
			entry = readdir(dir);
			while (entry != NULL)
			{
				if (ft_strcmp(entry->d_name, cmd) == 0)
					return (split_p[i]);
				entry = readdir(dir);
			}
		}
		closedir(dir);
		i++;
	}
	return (0);
}

void	execut_cmd(char *path, char **cmd, char *command, t_data *t)
{
	char	*full_path;
	int		word_count;
	int		i;
	char	**parmlist;

	full_path = ft_strjoin(path, cmd[0]);
	word_count = count_words(command, ' ');
	i = 0;
	parmlist = malloc(sizeof(char *) * word_count + 1);
	while (i < word_count)
	{
		parmlist[i] = cmd[i];
		i++;
	}
	parmlist[i] = NULL;
	i = fork();
	if (i == 0)
	{
		if (execve(full_path, parmlist, t->envp) == -1)
			exit(0);
	}
	else
		wait(&i);
	g_exit = WEXITSTATUS(i);
}
