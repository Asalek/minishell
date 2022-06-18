/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:10:18 by asalek            #+#    #+#             */
/*   Updated: 2022/05/20 17:10:19 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_echo(char *line)
{
	int		i;
	char	*echo;

	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	line = &line[i];
	echo = ft_substr(line, 0, 4);
	if (ft_strcmp(echo, "echo") == 0)
	{
		free(echo);
		return (1);
	}
	else
	{
		free(echo);
		return (0);
	}
}

int	check_qouts_(char *line, t_data *t)
{
	if (is_echo(line) == 1)
		return (1);
	t->z = 0;
	while (line[t->z])
	{
		if (line[t->z] == '\'')
		{
			if (check_single(line, t) == 0)
				return (0);
		}
		else if (line[t->z] == '"')
		{
			if (check_double(line, t) == 0)
				return (0);
		}
		t->z++;
	}
	return (1);
}
