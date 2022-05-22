/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:16:22 by asalek            #+#    #+#             */
/*   Updated: 2022/05/20 21:16:23 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handl_op_2(char *str, int i)
{
	int	t;

	t = i;
	i++;
	while (str[i] == '<')
		i++;
	if (i - t != 1)
	{
		if (i - t != 2)
			return (0);
	}
	return (1);
}

static int	handl_op(char *str, int i)
{
	int	t;

	t = i;
	i++;
	while (str[i] == '>')
		i++;
	if (i - t != 1)
	{
		if (i - t != 2)
			return (0);
	}
	return (1);
}

int	hendl_1(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '>')
		{
			if (handl_op(str, i) == 0)
			{
				printf("parse error near `>'\n");
				return (0);
			}
		}
		else if (str[i] == '<')
		{
			if (handl_op_2(str, i) == 0)
			{
				printf("parse error near `<'\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}
