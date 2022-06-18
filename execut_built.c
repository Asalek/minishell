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

int	more_built_(char **cmd, t_data *t)
{
	if (!ft_strcmp(cmd[0], "export"))
	{
		export(cmd[1], t);
		exit(0);
	}
	if (!ft_strcmp(cmd[0], "unset"))
	{
		unset(cmd[1], t);
		exit(0);
	}
	return (0);
}

int	more_built(char **cmd, t_data *t, char *cmdline)
{
	if (!ft_strcmp(cmd[0], "echo"))
	{
		ft_echo(cmdline, t);
		exit(0);
	}
	if (!ft_strcmp(cmd[0], "env"))
	{
		ft_env(t);
		exit(0);
	}
	if (!ft_strcmp(cmd[0], "pwd"))
	{
		pwd();
		exit(0);
	}
	return (more_built_(cmd, t));
}

int	execut_built_red(char **cmd, t_data *t, char *cmdline, int i)
{
	i = fork();
	if (i == 0)
	{
		dup2(t->f[1], 1);
		dup2(t->f[0], 0);
		if (!ft_strcmp(cmd[0], "cd"))
		{
			cd(cmd[1], t->envp);
			exit(0);
		}
		return (more_built(cmd, t, cmdline));
	}
	else
	{
		if (!ft_strcmp(cmd[0], "exit"))
			ft_exit();
		free_dp(cmd);
		free_dp(t->split_path);
		wait(&i);
	}
	g_exit = WEXITSTATUS(i);
	return (1);
}

void	execut_built(char *cmd, t_data *t)
{
	char	**cmd_split;
	int		i;

	cmd_split = ft_split(cmd, ' ');
	i = -1;
	while (cmd_split[++i])
	{
		check_quots(cmd_split[i]);
		remove_spaces(cmd_split[i]);
	}
	if (!cmd || !ft_strncmp(cmd, "", 1))
		return ;
	while (*cmd == ' ')
		cmd++;
	if (!strncmp("./", cmd, 2) || !strncmp("/", cmd, 1))
	{
		execut_cmd_2("", cmd_split, cmd, t);
		free_dp(cmd_split);
		return ;
	}
	if (execut_built_red(cmd_split, t, cmd, i))
		return ;
	free_dp(cmd_split);
}
