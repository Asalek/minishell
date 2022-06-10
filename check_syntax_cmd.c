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

int	check_3(char *line, t_echo *e)
{
	if (ft_strnstr(line, "echo", ft_strlen(line)))
	{
		if (check_qouts_echo(line, e) == 0)
		{
			{
				printf("invalid syntax quots\n");
				return (0);
			}
		}
	}
	else
	{
		if (check_qouts(line, e) == 0)
		{
			printf("invalid syntax quots\n");
			return (0);
		}
	}
	return (1);
}

int	check_2(char *line, t_echo *e, int i, t_data *t)
{
	e->parssing = split_pipe(line);
	if (!ft_strncmp(e->parssing[0], "", 1)
		|| !ft_strncmp(e->parssing[0], " ", 1))
	{
		g_exit = 258;
		return (printf("Phoenix: syntax error near unexpected token `|'\n"), 0);
	}
	while (e->parssing[i])
	{
		if (ft_strnstr(e->parssing[i], "echo", ft_strlen(e->parssing[i])))
		{
			if (check_qouts_echo(e->parssing[i], e) == 0)
				return (printf("invalid syntax quots\n"), 0);
		}
		else
		{
			if (check_qouts(e->parssing[i], e) == 0)
				return (printf("invalid syntax quots\n"), 0);
		}
		i++;
	}
	e->len = 0;
	while (e->parssing[e->len])
		e->len++;
	if (e->len > 1)
		pipee(e, t);
	else
	{
		g_exit = 258;
		return (printf("Phoenix: syntax error near unexpected token `|'\n"), 0);
	}
	return (1);
}

int	check_1(char *line, t_echo *e, t_data *t)
{
	if (ft_isthere(line, '|') == 1)
	{
		if (check_2(line, e, 0, t) == 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (check_3(line, e) == 0)
			return (0);
	}
	return (1);
}

int	redairection_handle(char *line)
{
	int	r;

	if (ft_strnstr(line, "echo", ft_strlen(line)))
	{
		r = check_if_is_echo(line);
		if (r == 0)
		{
			printf("command not found\n");
			return (0);
		}
	}
	if (hendl_1(line, 0) == 0)
		return (0);
	return (1);
}

char	*line_handle(char *line, t_echo *e, t_data *t)
{
	if (check_1(line, e, t) == 0)
		return (0);
	else if (ft_isthere(line, '|') == 0)
		handl_line(line, t);
	return ("ok");
}
