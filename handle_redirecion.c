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

static	void	ft_fr(t_data *t, char *line)
{
	if (t->cmd)
	{
		free(line);
		line = NULL;
	}
	if (t->command)
	{
		free(t->command);
		t->command = NULL;
	}
}

void create_files(char *line, t_data *t)
{
	int		i;
	int		x;
	char	*str;

	t->len = 1;
	i = 0;
	while (line[i])
	{
		x = return_i(line);
		str = ft_substr(line, 0, x);
		rdirect_1(str, t);
		free(str);
		line = &line[x];
		i = 0;
	}

}

static int	check_(char *cmd, char *line, t_data *t)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ')
		i++;
	if (i == (int)ft_strlen(cmd))
	{
		 
		create_files(line, t);
		return (0);
	}
	else
	{

		redirect_files(line, t);
		return (1);
	}
}

static	void	red_(t_data *t, char *line)
{
	if (count_herdoc(line, t))
		herdoc_call(line, t);
	else
	{
		
		if (check_(t->command, line, t) == 0)
			return ;
	}
}

void	redirection(char *line, t_data *t)
{
	t->cmd = NULL;
	t->command = NULL;
	while (*line && *line == ' ')
		line++;
	if (*line == '>'
		|| (*line == '<' && *(line + 1) != '<'))
	{
		reverse_cmd(line, t);
		line = t->cmd;
	}
	collect_cmd(line, t);
	if (check_qouts_(t->command, t) == 0)
	{
		g_exit = 1;
		perror(t->command);
		return ;
	}
	red_(t, line);
	ft_fr(t, line);
}
