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
		// rl_replace_line("", 0);
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

	if (c == '\'')
		a = '\'';
	else if (c == '"')
		a = '"';
	return (a);
}

int	check_quots(char *cmd)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	j = 0;
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