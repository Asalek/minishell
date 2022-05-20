/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_syntax_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:11:22 by asalek            #+#    #+#             */
/*   Updated: 2022/05/20 17:36:55 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_single_quots(char *line, t_echo *e)
{
	int	t;

	t = e->i;
	e->i++;
	while (line[e->i] && line[e->i] != '\'')
		e->i++;
	if (line[e->i] == '\'')
		return (1);
	else
		return (0);
}

int	check_double_quots(char *line, t_echo *e)
{
	int	t;

	t = e->i;
	e->i++;
	while (line[e->i] && line[e->i] != '"')
		e->i++;
	if (line[e->i] == '"')
		return (1);
	else
		return (0);
}

int	check_single(char *line, t_echo *e)
{
	int	t;

	t = e->i;
	e->i++;
	while (line[e->i] && line[e->i] != '\'' && line[e->i] != ' ')
		e->i++;
	if (line[e->i] == '\'')
		return (1);
	else
		return (0);
}

int	check_double(char *line, t_echo *e)
{
	int	t;

	t = e->i;
	e->i++;
	while (line[e->i] && line[e->i] != '"' && line[e->i] != ' ')
		e->i++;
	if (line[e->i] == '"')
		return (1);
	else
		return (0);
}

int	check_qouts(char *line, t_echo *e)
{
	e->i = 0;
	while (line[e->i])
	{
		if (line[e->i] == '\'')
		{
			if (check_single(line, e) == 0)
				return (0);
		}
		else if (line[e->i] == '"')
		{
			if (check_double(line, e) == 0)
				return (0);
		}
		e->i++;
	}
	return (1);
}

