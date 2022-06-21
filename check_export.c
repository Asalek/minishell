/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:38:58 by asalek            #+#    #+#             */
/*   Updated: 2022/05/24 21:19:59 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	chech_export(char *str)
{
	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		printf("Phoenix> bad identifier\n");
		g_exit = 1;
		return (0);
	}
	return (1);
}

int	check_spaces(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			if (str[i - 1] == ' ')
			{
				printf("Phoenix> bad identifier\n");
				g_exit = 1;
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_export_arg(t_data *a, char *line, t_data *t)
{
	a->cmd = ft_strcut(line, 7, ft_strlen(line));
	a->commands = ft_split(a->cmd, '=');
	if (a->commands[0][0] == '"' || a->commands[0][0] == '\'')
		a->str = ft_strcut(a->commands[0], 1, ft_strlen(a->commands[0]) - 2);
	else
		a->str = a->commands[0];
	if (a->commands[1]
		&& (a->commands[1][0] == '"' || a->commands[1][0] == '\''))
		a->str2 = ft_strcut(a->commands[1], 1, ft_strlen(a->commands[1]) - 2);
	else
	{
		if (!a->commands[1])
			a->str2 = NULL;
		else
			a->str2 = a->commands[1];
	}
	if (!chech_export(a->str))
		return (free_all(a->cmd, a->commands, NULL), 0);
	if (!check_spaces(line))
		return (free_all(a->cmd, a->commands, NULL), 0);
	if (is_in_node(t->env_list, a->str, a->str2))
		return (free_all(a->cmd, a->commands, NULL), 0);
	return (1);
}
