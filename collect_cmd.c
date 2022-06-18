/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:00:52 by messalih          #+#    #+#             */
/*   Updated: 2021/12/07 21:03:23 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	complete_cmd_2(char *line, t_data *t, int i)
{
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (che_ckspace(&line[i]))
	{
		t->commands[t->i] = ft_substr(&line[i], 0, ft_strlen(&line[i]));
			t->i++;
	}
}

static	void	complete_cmd_1(char *line, t_data *t, int i)
{
	if (line[i] == '\'' || line[i] == '"')
	{
		i++;
		while (line[i]
			&& line[i] != '\'' && line[i] != '"')
			i++;
		i++;
		while (line[i] && line[i] == ' ')
			i++;
		if (che_ckspace(&line[i]))
		{
			t->commands[t->i] = ft_substr(&line[i], 0, ft_strlen(&line[i]));
			t->i++;
		}
	}
	else
		complete_cmd_2(line, t, i);
}

static	void	comp_cmd_1(char *line, t_data *t, int i)
{
	while (line[i] && (line[i] == '<' || line[i] == '>'))
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	complete_cmd_1(line, t, i);
}

void	complete_cmd(char *line, t_data *t)
{
	int	i;

	i = 0;
	if (t->x == 0)
	{
		if (line[0] == '<' && line[1] == '<')
		{
			i = 2;
			while (line[i] && line[i] == ' ')
				i++;
			complete_cmd_1(line, t, i);
		}
		else
		{
			t->commands[t->i] = ft_substr(line, 0, ft_strlen(line));
			t->i++;
		}
		t->x = 10;
	}
	else
		comp_cmd_1(line, t, i);
}
