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

int	input_red_(char *line, int x, t_data *t)
{
	x++;
	t->i = x;
	while (line[x]
		&& line[x] != '"' && line[x] != '\'')
		x++;
	t->file = ft_substr(line, t->i, x - t->i);
	if (open(t->file, O_RDONLY) == -1)
	{
		if (t->m != 10)
		{
			t->f1 = t->file;
			t->m = 10;
		}
		return (0);
	}
	else
	{
		t->z = open(t->file, O_RDONLY);
		free(t->file);
		return (t->z);
	}
}

int	in_put_red(t_data *t, char *file)
{
	int	fd;

	if (open(file, O_RDONLY) == -1)
	{
		if (t->m != 10)
		{
			t->f1 = file;
			t->m = 10;
		}
		return (0);
	}
	else
	{
		fd = open(file, O_RDONLY);
		free(file);
		return (fd);
	}
}

int	input_red(char *line, t_data *t)
{
	int		i;
	int		x;
	char	*file;

	x = 1;
	while (line[x] == ' ' && line[x] != '\0' )
		x++;
	if (line[x] == '"' || line[x] == '\'')
		return (input_red_(line, x, t));
	i = x;
	while (line[x] != ' ' && line[x] != '\0' )
		x++;
	file = ft_substr(line, i, x - i);
	return (in_put_red(t, file));
}
