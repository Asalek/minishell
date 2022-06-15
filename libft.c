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

size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

void	remove_spaces(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ' ' && ft_strlen(str) < 2) // ""
		return ;	
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i])
			{
				str[i] = str[i + 1];
				i++;
			}
		}
		i++;
	}
	str[i] = '\0';
}

void	remove_space_quotes(char **cmd_split)
{
	int	i;

	i = 1;
	while (cmd_split[i])
	{
		check_quots(cmd_split[i]);
		remove_spaces(cmd_split[i]);
		i++;
	}
}

int	unclosed_quotes(char *str)
{
	int	i;
	int	n;
	int	s;

	i = 0;
	n = 0;
	s = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			n++;
		else if (str[i] == '"')
			s++;
		i++;
	}
	if (n % 2 != 0)
		return (1);
	if (s % 2 != 0)
		return (1);
	else
		return (0);
}
