/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:19:06 by asalek            #+#    #+#             */
/*   Updated: 2022/06/04 20:29:58 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_arg_env(char *str, t_data *t)
{
	t_list2	*p;

	p = NULL;
	if (!ft_strncmp(str, "?", 1))
		return (ft_itoa(g_exit));
	p = t->env_list;
	while (p)
	{
		if (!ft_strcmp(str, p->name))
		{
			return (p->value);
		}
		p = p->next;
	}
	return ("");
}

int	count_er(char *line)
{
	int		i;
	int		x;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		x = return_i(line);
		count++;
		line = &line[x];
		i = 0;
	}
	return (count);
}
