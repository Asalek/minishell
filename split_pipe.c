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

char	*ft_strcutt(char *str, int start, int end)
{
	int		i;
	char	*string;

	i = start;
	while (i < end)
		i++;
	string = malloc((end - i) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		string[i] = str[start];
		i++;
		start++;
	}
	string[i] = '\0';
	return (string);
}

int	count_pipes(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == '|')
			x++;
		i++;
	}
	return (x);
}

int	quotes(char *str, int i)
{
	if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\'')
			i++;
	}
	else if (str[i] == '\"')
	{
		i++;
		while (str[i] != '\"')
			i++;
	}
	return (i);
}

char	**split_pipe(char *str)
{
	t_echo	t;

	t.i = 0;
	t.l = 0;
	t.j = 0;
	t.alloc = (char **)malloc(sizeof(char *) * (count_pipes(str) + 2));
	while (str[t.i])
	{
		if (str[t.i] == '\'' || str[t.i] == '\"')
			t.i = quotes(str, t.i) + 1;
		if (str[t.i] == '|')
		{
			t.alloc[t.l] = ft_strcutt(str, t.j, t.i);
			t.j = t.i + 1;
			t.l++;
		}
		if (str[t.i + 1] == '\0')
		{
			t.alloc[t.l] = ft_strcutt(str, t.j, t.i + 1);
			t.l++;
			t.alloc[t.l] = NULL;
		}
		t.i++;
	}
	return (t.alloc);
}

int	che_ckspace(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (i == (int)ft_strlen(line))
		return (0);
	return (1);
}
