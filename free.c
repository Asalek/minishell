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

void	free_dp(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr || !ptr[0] || ptr == NULL || ptr[0][0] == '\0')
		return ;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
}

void	free_dp_1(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr || !ptr[0] || ptr == NULL || ptr[0][0] == '\0')
	{
		exit(0);
		return ;
	}
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
	exit(0);
}

void	free_pointer(char *str)
{
	if (!str || !str[0] || str == NULL || str[0] == '\0')
		return ;
	if (str)
	{
		free(str);
	}
}

void	free_all(char *str, char **tab, t_list2 *t)
{
	t_list2	*p;

	free_pointer(str);
	free_dp(tab);
	while (t)
	{
		p = t;
		t = t->next;
		free(p->name);
		free(p->value);
		free(p);
	}
}

void	free_all_2(char *s, char *s1, char **str, char **tab)
{
	free_pointer(s);
	free_pointer(s1);
	free_dp(str);
	free_dp(tab);
}
