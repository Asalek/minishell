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

void	exit_shell(int a)
{
	if (a == SIGINT)
	{
		g_exit = 1;
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (a == SIGQUIT)
	{
		ft_putstr_fd("\r", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

char	single_or_double(char c)
{
	char	a;

	a = 'a';
	if (c == '\'')
		a = '\'';
	else if (c == '"')
		a = '"';
	return (a);
}

int	check_quots(char *cmd)
{
	int		i;
	char	c;

	i = -1;
	c = single_or_double(cmd[0]);
	if (c != '\'' && c != '"')
		return (0);
	cmd[0] = ' ';
	cmd++;
	while (cmd[++i])
	{
		if (cmd[i] == c)
		{
			while (cmd[i])
			{
				cmd[i] = cmd[i + 1];
				i++;
			}
		}
		else if (cmd[i] == ' ')
			return (127);
	}
	cmd[i] = '\0';
	return (0);
}

char	single_or_double_pipe(char *c)
{
	char	a;
	int		i;

	i = 0;
	a = 'a';
	while (c[i])
	{
		if (c[i] == '\'')
			a = '\'';
		else if (c[i] == '"')
			a = '"';
		i++;
	}
	return (a);
}

int	check_quots_pipe(char *cmd)
{
	int		i;
	char	c;

	c = single_or_double_pipe(cmd);
	if (c != '\'' && c != '"')
		return (0);
	i = -1;
	while (cmd[++i])
		if (cmd[i] == c)
			break ;
	cmd[i] = ' ';
	while (cmd[++i])
	{
		if (cmd[i] == c)
		{
			while (cmd[i])
			{
				cmd[i] = cmd[i + 1];
				i++;
			}
		}
		else if (cmd[i] == ' ')
			return (g_exit = 127, 12);
	}
	return (cmd[i] = '\0', 0);
}


//rl_replace_line("", 0);  22