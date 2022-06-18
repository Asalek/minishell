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

size_t	count_commands(t_data *t)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (t->commands[i])
	{
		len += ft_strlen(t->commands[i]);
		i++;
	}
	return (len);
}

void	comple_te_cmd(char *line, t_data *t)
{
	size_t	len;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	len = count_commands(t);
	t->command = malloc(sizeof(char) * (len * 2) + 1);
	while (t->commands[i])
	{
		y = 0;
		while (t->commands[i][y])
		{
			t->command[x] = t->commands[i][y];
			y++;
			x++;
		}
		t->command[x] = ' ';
		x++;
		i++;
	}
	t->command[x] = '\0';
}

void	alloc_commands(t_data *t, char *line)
{
	int		i;
	int		x;
	char	*str;

	t->x = 0;
	t->i = 0;
	i = 0;
	while (line[i])
	{
		x = return_i(line);
		str = ft_substr(line, 0, x);
		complete_cmd(str, t);
		free(str);
		line = &line[x];
		i = 0;
	}
	t->commands[t->i] = NULL;
}

void	collect_cmd(char *line, t_data *t)
{
	int	i;

	i = 0;
	t->commands = malloc(sizeof(char *) * (count_er(line) + 1));
	alloc_commands(t, line);
	comple_te_cmd(line, t);
	while (t->commands[i])
		free(t->commands[i++]);
	free(t->commands);
}
