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

void	rdirect_1(char *line, t_data *t)
{
	if(t->len == 1)
	{
		if (line[0] == '>' && line[1] == '>')
			t->f[1] = append_red(line, t);
		else if (line[0] == '>' && line[1] != '>')
			t->f[1] = output_red(line, t);
		else if (line[0] == '<' && line[1] == '<')
			t->f[0] = open("/tmp/phenix.txt", O_RDWR, 0777);
		else if (line[0] == '<' && line[1] != '<')
			t->f[0] = input_red(line, t);
		return ;
	}
	else
	{
		if (line[0] == '>' && line[1] == '>')
			t->f[1] = append_red(line, t);
		else if (line[0] == '>' && line[1] != '>')
			t->f[1] = output_red(line, t);
		else if (line[0] == '<' && line[1] == '<')
			t->f[0] = open("/tmp/phenix.txt", O_RDWR, 0777);
		else if (line[0] == '<' && line[1] != '<')
			t->f[0] = input_red(line, t);
	}
}

void	execut_red_bult(char *line, t_data *t)
{
	int		i;
	int		x;
	char	*str;

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
	execut_built(t->command, t);
}

void	red_file_sys(char *line, t_data *t)
{
	int		i;
	int		x;
	char	*str;

	if (command_found(t->command, t) == 0)
		return ;
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
	if (t->m == 10)
	{
		perror(t->f1);
		return ;
	}
	file_sys_red(t->command, t);
}

void	redirect_files(char *line, t_data *t)
{
	int	i;
	int	x;

	t->f[0] = 0;
	t->f[1] = 1;
	t->i = 0;
	t->m = 0;
	if (if_is_bult(t->command, t))
		execut_red_bult(line, t);
	else
		red_file_sys(line, t);
}
