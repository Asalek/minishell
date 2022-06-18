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

int	check_single_quots(char *line, t_data *t)
{
	t->z++;
	while (line[t->z] && line[t->z] != '\'')
		t->z++;
	if (line[t->z] == '\'')
		return (1);
	else
		return (0);
}

int	check_double_quots(char *line, t_data *t)
{
	t->z++;
	while (line[t->z] && line[t->z] != '"')
		t->z++;
	if (line[t->z] == '"')
		return (1);
	else
		return (0);
}

int	check_single(char *line, t_data *t)
{
	t->z++;
	while (line[t->z]
		&& line[t->z] != '\'' && line[t->z] != ' ')
		t->z++;
	if (line[t->z] == '\'')
		return (1);
	else
		return (0);
}

int	check_double(char *line, t_data *t)
{
	t->z++;
	while (line[t->z]
		&& line[t->z] != '"' && line[t->z] != ' ')
		t->z++;
	if (line[t->z] == '"')
		return (1);
	else
		return (0);
}
