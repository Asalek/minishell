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

int	check_2(char *line, t_echo *e, t_data *t)
{
	e->parssing = split_pipe(line);
	if (!ft_strncmp(e->parssing[0], "", 1)
		|| !ft_strncmp(e->parssing[0], " ", 1))
	{
		g_exit = 258;
		return (printf("Phoenix: syntax error near unexpected token `|'\n"), 0);
	}
	e->len = 0;
	while (e->parssing[e->len])
	{
		check_quots(e->parssing[e->len]);
		e->len++;
	}	
	if (e->len > 1)
		pipee(e, t);
	else
	{
		g_exit = 258;
		return (printf("Phoenix: syntax error near unexpected token `|'\n"), 0);
	}
	free_dp(e->parssing);
	return (1);
}

int	pipe_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i = quotes(str, i);
		if (str[i] == '|')
		{
			i++;
			if (str[i] == '|')
				return (printf("Phoenix: syntax error near unexpected token `|'\n"), 0);
			while (str[i] == ' ')
			{
				if (str[i + 1] == '|' || str[i + 1] == '\0')
					return (printf("Phoenix: syntax error near unexpected token `|'\n"), 0);
				else
					i++;
			}
			if (str[i] == '\0')
				return (printf("Phoenix: syntax error near unexpected token `|'\n"), 0);

		}
		i++;
	}
	return (1);
}

char	*line_handle(char *line, t_echo *e, t_data *t)
{
	if (ft_isthere(line, '|') == 1 && check_pipe_inside_quotes(line)) 
	{
		if (!pipe_syntax(line))
			return (0);
		if (check_2(line, e, t) == 0)
			return (0);
	}
	else
		handl_line(line, t);
	return ("ok");
}
