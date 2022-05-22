/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:14:07 by asalek            #+#    #+#             */
/*   Updated: 2022/05/22 15:46:03 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	more_built_in(char **cmd, t_data *t)
{
	if (!ft_strcmp(cmd[0], "export"))
	{
		export(cmd[1], t);
		return (1);
	}
	if (!ft_strcmp(cmd[0], "unset"))
	{
		if (!cmd[1])
		{
			printf("unset: not enough arguments\n");
			g_exit = 1;
			return (1);
		}
		unset(cmd[1], t);
		return (1);
	}
	else
		return (0);
}

int	built_in_functions(char **cmd, t_data *t)
{
	if (!ft_strcmp(cmd[0], "cd"))
	{
		cd(cmd[1], t->envp);
		return (1);
	}
	if (!ft_strcmp(cmd[0], "pwd"))
	{
		printf("%s\n", pwd());
		return (1);
	}
	if (!ft_strcmp(cmd[0], "exit"))
		ft_exit();
	if (!ft_strcmp(cmd[0], "echo"))
	{
		ft_echo(cmd, t);
		return (1);
	}
	if (!ft_strcmp(cmd[0], "env"))
	{
		ft_env(t);
		return (1);
	}
	else
		return (more_built_in(cmd, t));
}

void	handl_line(char *cmd, t_data *t)
{
	char	*path;
	char	**split_p;
	char	**cmd_split;

	path = return_path(t->envp);
	t->i = count_words(path, ':');
	split_p = split_path(path);
	cmd_split = ft_split(cmd, ' ');
	if (!cmd || !ft_strncmp(cmd, "", 1))
		return ;
	while (*cmd == ' ')
		cmd++;
	if (built_in_functions(cmd_split, t))
		return ;
	else if (!strncmp("./", cmd, 2) || !strncmp("/", cmd, 1))
		execut_cmd("", cmd_split, cmd, t);
	else if (cmd_found(t->i, split_p, cmd_split[0]) == 0)
	{
		printf("COMMAND NOT FOUND\n");
		g_exit = 127;
	}
	else
		execute_path(t, split_p, cmd_split, cmd);
}

int	check_line(char *str, t_data *t, t_echo *e)
{
	char	*cmd;

	e->l = 0;
	e->i = 0;
	if (!strncmp(str, "$", 1))
	{
		str++;
		cmd = replace_arg_env(str, t);
		handl_line(cmd, t);
		return (0);
	}
	if (ft_strlen(str) < 1)
		return (0);
	check_quots(str);
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

	signal(SIGQUIT, exit_shell);
	signal(SIGINT, exit_shell);
	e = malloc(sizeof(t_echo));
	ft_strnstr(argv[0], ft_itoa(argc), 2);
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
}
