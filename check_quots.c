/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:53:53 by asalek            #+#    #+#             */
/*   Updated: 2022/05/22 18:20:04 by asalek           ###   ########.fr       */
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
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (a == SIGQUIT)
	{
		ft_putstr_fd("\r", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	check_quots(char *cmd)
{
	int		i;
	char	c;
	int		len;

	len = ft_strlen(cmd);
	i = 0;
	if ((*cmd == '\"' && cmd[len - 1] == '\"')
		|| (*cmd == '\'' && cmd[len - 1] == '\''))
	{
		while (cmd[i])
		{		
			c = cmd[i + 1];
			cmd[i] = c;
			i++;
		}
		i--;
		cmd[i - 1] = '\0';
	}
}
