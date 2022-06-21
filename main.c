/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:14:07 by asalek            #+#    #+#             */
/*   Updated: 2022/05/31 12:48:49 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	more_built_in(char **cmd, t_data *t, char *line)
{
	if (!ft_strcmp(cmd[0], "export"))
	{
		export(cmd[1], t, line);
		return (free_dp(cmd), free_dp(t->split_path), 1);
	}
	if (!ft_strcmp(cmd[0], "unset"))
	{
		if (!cmd[1])
		{
			printf("unset: not enough arguments\n");
			g_exit = 1;
			return (free_dp(cmd), free_dp(t->split_path), 1);
		}
		unset(cmd[1], t);
		return (free_dp(cmd), free_dp(t->split_path), 1);
	}
	else
		return (0);
}

int	built_in_functions(char **cmd, t_data *t, char *cmdline)
{
	if (!ft_strcmp(cmd[0], "cd"))
	{
		cd(cmd[1], t->envp);
		return (free_dp(cmd), free_dp(t->split_path), 1);
	}
	if (!ft_strcmp(cmd[0], "pwd"))
	{
		pwd();
		return (free_dp(cmd), free_dp(t->split_path), 1);
	}
	if (!ft_strcmp(cmd[0], "exit"))
		ft_exit();
	if (!ft_strcmp(cmd[0], "echo"))
	{
		ft_echo(cmdline, t);
		return (free_dp(cmd), free_dp(t->split_path), 1);
	}
	if (!ft_strcmp(cmd[0], "env"))
	{
		ft_env(t);
		return (free_dp(cmd), free_dp(t->split_path), 1);
	}
	else
		return (more_built_in(cmd, t, cmdline));
}

void	handl_line(char *cmd, t_data *t)
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
		return ;
	while (*cmd == ' ')
		cmd++;
	if (built_in_functions(cmd_split, t, cmd))
		return ;
	else if (!strncmp("./", cmd, 2) || !strncmp("/", cmd, 1))
		execut_cmd("", cmd_split, cmd, t);
	else if (cmd_found(t->i, t->split_path, cmd_split) == 0)
		printf("COMMAND NOT FOUND\n");
	else
		execute_path(t, t->split_path, cmd_split, cmd);
}

int	check_line(char *str, t_data *t, t_echo *e)
{
	e->l = 0;
	e->i = 0;
	if (unclosed_quotes(str) == 1)
	{
		g_exit = 130;
		return (printf("invalid syntax quots\n"), 0);
	}
	while (str[e->i] && str[e->i] == ' ')
	{
		if (str[(e->i + 1)] == '\0')
			return (0);
		e->i++;
	}
	while (*str == ' ')
		str++;
	if (ft_strlen(str) < 1)
		return (0);
	if (check_quots(str) == 127)
		return (g_exit = 127, printf("Phoenix> command not found\n"), 0);
	if (str[0] == ' ' && ft_strlen(str) < 2)
		return (printf("command not found\n"), g_exit = 127, 0);
	if (line_handle(str, e, t) == NULL)
		return (0);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_list2	*list;
	t_data	t;
	t_echo	*e;

	(void)argc;
	(void)argv;
	signal(SIGQUIT, exit_shell);
	signal(SIGINT, exit_shell);
	e = malloc(sizeof(t_echo));
	list = creat_list(envp);
	t.envp = envp;
	t.env_list = list;
	line = readline(PROMPT);
	while (line)
	{
		if (ft_isprint(line[0]))
			add_history(line);
		check_line(line, &t, e);
		free(line);
		line = readline(PROMPT);
	}
	free_all(NULL, NULL, list);
	free(e);
}
