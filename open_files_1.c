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

int	appe_nd_red(char *line, int x, t_data *t)
{
	int		i;
	int		fd;
	char	*file;

	x++;
	i = x;
	while (line[x]
		&& line[x] != '"' && line[x] != '\'')
		x++;
	file = ft_substr(line, i, x - i);
	fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0777);
	free(file);
	return (fd);
}

int	append_red(char *line, t_data *t)
{
	int		i;
	int		x;
	int		fd;
	char	*file;

	x = 2;
	while (line[x] == ' ' && line[x] != '\0')
		x++;
	i = x;
	if (line[x] == '"' || line[x] == '\'')
		return (appe_nd_red(line, x, t));
	else
	{
		while (line[x] != ' ' && line[x] != '\0')
			x++;
		file = ft_substr(line, i, x - i);
		fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0777);
		free(file);
		return (fd);
	}
}

int	out_put_red(char *line, int x, t_data *t)
{
	int		i;
	int		fd;
	char	*file;

	x++;
	i = x;
	while (line[x]
		&& line[x] != '"' && line[x] != '\'')
		x++;
	file = ft_substr(line, i, x - i);
	fd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0777);
	free(file);
	return (fd);
}

int	output_red(char *line, t_data *t)
{
	int		i;
	int		x;
	int		fd;
	char	*file;

	x = 1;
	while (line[x] == ' ' && line[x] != '\0')
		x++;
	i = x;
	if (line[x] == '"' || line[x] == '\'')
		return (out_put_red(line, x, t));
	else
	{
		while (line[x] != ' ' && line[x] != '\0')
			x++;
		file = ft_substr(line, i, x - i);
		fd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0777);
		free(file);
		return (fd);
	}
}
