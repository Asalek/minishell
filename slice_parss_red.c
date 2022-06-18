/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:21:49 by asalek            #+#    #+#             */
/*   Updated: 2022/06/04 16:17:33 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	return_i(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '<' || line[i] == '>')
	{
		while (line[i] == '<' || line[i] == '>')
			i++;
	}
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			i++;
			while (line[i]
				&& line[i] != '\'' && line[i] != '"')
				i++;
		}
		else if (line[i] == '<' || line[i] == '>')
			return (i);
		i++;
	}
	return (i);
}

static	int	red_pars(char *line, int i)
{
	while (line[i] && line[i] == '<')
		i++;
	if (i > 2)
		return (0);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\0'
		|| line[i] == '<' || line[i] == '>')
		return (0);
	return (1);
}

int	red_parss(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '>')
	{
		while (line[i] && line[i] == '>')
			i++;
		if (i > 2)
			return (0);
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '\0'
			|| line[i] == '<' || line[i] == '>')
			return (0);
		return (1);
	}
	else if (line[i] == '<')
		return (red_pars(line, i));
	return (1);
}

int	red_parssing(char *line)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	while (line[i])
	{
		x = return_i(line);
		str = ft_substr(line, 0, x);
		if (red_parss(str) == 0)
		{
			free(str);
			return (0);
		}
		free(str);
		line = &line[x];
		i = 0;
	}
	return (1);
}

int	count_herdoc(char *line, t_data *t)
{
	int		i;
	int		x;
	char	*herdoc;

	t->len = 0;
	i = 0;
	while (line[i])
	{
		x = return_i(line);
		herdoc = ft_substr(line, 0, x);
		if (herdoc[0] == '<' && herdoc[1] == '<')
			t->len++;
		free(herdoc);
		line = &line[x];
		i = 0;
	}
	return (t->len);
}
