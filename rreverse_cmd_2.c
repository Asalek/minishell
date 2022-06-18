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

void	fill_2(int x, int i, t_data *t)
{
	while (t->str[i])
	{
		t->cmd[x] = t->str[i];
		x++;
		i++;
	}
	t->cmd[x] = ' ';
	x++;
	t->cmd[x] = '\0';
}

void	fill_1(int x, int i, t_data *t)
{
	while (t->op[i])
	{
		t->cmd[x] = t->op[i];
		x++;
		i++;
	}
	t->cmd[x] = ' ';
	x++;
	i = 0;
	while (t->file[i])
	{
		t->cmd[x] = t->file[i];
		x++;
		i++;
	}
	t->cmd[x] = ' ';
	x++;
	fill_2(x, 0, t);
}
