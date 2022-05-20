/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:53:53 by asalek            #+#    #+#             */
/*   Updated: 2022/05/20 20:31:01 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(int a)
{
	(void)a;
	return ;
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
