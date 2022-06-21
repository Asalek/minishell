/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:14:07 by asalek            #+#    #+#             */
/*   Updated: 2022/05/31 12:48:49 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	red_herd(char *line, t_data *t)
{
	int		i;
	int		fd;
	char	*str;

	t->x = 0;
	fd = open("/tmp/phenix.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	str = readline(">");
	while (str && ft_strcmp(str, line) != 0)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
		str = readline(">");
	}
	free(str);
	close(fd);
	return (1);
}

void	c_all_herdoc(char *line, int i, t_data *t, int x)
{
	char	*s;

	while (line[i] && line[i] != ' ')
		i++;
	s = ft_substr(line, x, i - x);
	red_herd(s, t);
	free(s);
}

int	call_herdoc_(char *line, t_data *t)
{
	char	*s;

	t->i = 2;
	if (line[0] == '<' && line[1] == '<')
	{
		while (line[t->i] && line[t->i] == ' ')
			t->i++;
		t->x = t->i;
		if (line[t->i] == '"' || line[t->i] == '\'')
		{
			t->i++;
			t->x = t->i;
			while (line[t->i]
				&& line[t->i] != '"' && line[t->i] != '\'')
				t->i++;
			s = ft_substr(line, t->x, t->i - t->x);
			red_herd(s, t);
			free(s);
		}
		else
			c_all_herdoc(line, t->i, t, t->x);
	}
	return (1);
}

int	call_herdoc(char *line, t_data *t)
{
	int		i;
	int		x;
	char	*herdoc;

	i = 0;
	while (line[i])
	{
		x = return_i(line);
		herdoc = ft_substr(line, 0, x);
		call_herdoc_(herdoc, t);
		free(herdoc);
		line = &line[x];
		i = 0;
	}
	return (1);
}

void	herdoc_call(char *line, t_data *t)
{
	int	i;

	if (call_herdoc(line, t))
	{
		while (t->command[i] == ' ')
			i++;
		if (i == (int)ft_strlen(t->command))
		{
			create_files(line, t);
			return ;
		}
		redirect_files(line, t);
	}
}
