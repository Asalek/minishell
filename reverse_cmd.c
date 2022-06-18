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

static	void	reverse_cmd_3(t_data *t)
{
	size_t	len;
	int		i;
	int		x;

	x = 0;
	i = 0;
	len = ft_strlen(t->str2) + ft_strlen(t->op)
		+ ft_strlen(t->file) + ft_strlen(t->str);
	t->cmd = malloc(sizeof(char) * (100) + 1);
	t->str2 = ft_substr(t->temp, t->j, t->i - t->j);
	while (t->str2[i])
	{
		t->cmd[x] = t->str2[i];
		x++;
		i++;
	}
	t->cmd[x] = ' ';
	x++;
	fill_1(x, 0, t);
}

static	void	reverse_cmd_3_(t_data *t)
{
	while (t->temp[t->i] && t->temp[t->i] == ' ')
		t->i++;
	t->j = t->i;
	while (t->temp[t->i])
		t->i++;
	reverse_cmd_3(t);
}

static	void	reverse_cmd_2(t_data *t)
{
	if (t->temp[t->i] == '"' || t->temp[t->i] == '\'')
	{
		t->j = t->i;
		t->i++;
		while (t->temp[t->i]
			&& t->temp[t->i] != '\'' && t->temp[t->i] != '"')
			t->i++;
		t->i++;
		t->file = ft_substr(t->temp, t->j, t->i - t->j);
	}
	else
	{
		t->j = t->i;
		while (t->temp[t->i] && t->temp[t->i] != ' ')
			t->i++;
		t->file = ft_substr(t->temp, t->j, t->i - t->j);
	}
	reverse_cmd_3_(t);
}

void	reverse_cmd(char *line, t_data *t)
{
	t->i = 0;
	t->j = t->i;
	while (line[t->i] == '<' || line[t->i] == '>')
		t->i++;
	t->op = ft_substr(line, t->j, t->i - t->j);
	t->j = t->i;
	t->x = return_i(line);
	t->str = &line[t->x];
	t->temp = ft_substr(line, t->j, t->x - t->j);
	t->i = 0;
	while (t->temp[t->i] == ' ' && t->temp[t->i])
		t->i++;
	reverse_cmd_2(t);
	free(t->op);
	free(t->temp);
	free(t->file);
	free(t->str2);
}
