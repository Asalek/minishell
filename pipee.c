/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipee.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:41:04 by asalek            #+#    #+#             */
/*   Updated: 2022/06/04 16:11:28 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	execut_cmdd(char *path, char **cmd, char *command, t_data *t)
{
	char	*full_path;
	char	**parmlist;
	int		word_count;
	int		i;

	full_path = ft_strjoin(path, cmd[0]);
	word_count = count_words(command, ' ');
	i = 0;
	parmlist = malloc(sizeof(char *) * word_count + 1);
	while (i < word_count)
	{
		parmlist[i] = cmd[i];
		check_quots(parmlist[i]);
		i++;
	}
	parmlist[i] = NULL;
	if (execve(full_path, parmlist, t->envp) == -1)
		exit(0);
}

void	handl_linee(char *cmd, t_data *t)
{
	char	*path;
	char	*full_path;
	char	**cmd_split;

	path = return_path(t->envp);
	t->bool_fd = count_words(path, ':');
	t->split_path = split_path(path);
	cmd_split = ft_split(cmd, ' ');
	full_path = cmd_found(t->bool_fd, t->split_path, cmd_split);
	if (!cmd || !ft_strncmp(cmd, "", 1))
		return ;
	while (*cmd == ' ')
		cmd++;
	remove_space_quotes(cmd_split);
	if (built_in_functions(cmd_split, t, cmd))
		exit(0);
	else if (!strncmp("./", cmd, 2))
		execut_cmdd("", cmd_split, cmd, t);
	else if (!strncmp("/", cmd, 1))
		execut_cmdd("", cmd_split, cmd, t);
	else if (full_path == 0)
		command_not_found(0);
	full_path = concatenate_string(full_path, "/");
	execut_cmdd(full_path, cmd_split, cmd, t);
}

void	pipe_closing(int *fd, int len)
{
	int	i;

	i = 0;
	while (i < 2 * len)
	{
		close(fd[i]);
		i++;
	}
	free(fd);
}

void	wait_for_childs(int len, int pid)
{
	int	i;

	i = 0;
	while (i < len)
	{
		wait(NULL);
		i++;
	}
	g_exit = WEXITSTATUS(pid);
}

void	pipee(t_echo *e, t_data *t)
{
	int	*fd;

	e->i = -1;
	e->j = 0;
	e->t = 0;
	fd = malloc(2 * count(e->parssing) * sizeof(int));
	while (++e->i < count(e->parssing))
		pipe(fd + e->i * 2);
	while (e->parssing[e->t] != NULL)
	{
		t->pid = fork();
		if (t->pid == 0)
		{
			if (e->parssing[e->t + 1] != NULL)
				dup2(fd[e->j + 1], 1);
			if (e->j != 0)
				dup2(fd[e->j - 2], 0);
			pipe_closing(fd, count(e->parssing));
			handl_linee(e->parssing[e->t], t);
		}
		e->t++;
		e->j += 2;
	}
	pipe_closing(fd, count(e->parssing));
	wait_for_childs(count(e->parssing), t->pid);
}
