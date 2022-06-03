/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_additional.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:44:13 by asalek            #+#    #+#             */
/*   Updated: 2022/06/03 16:33:32 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		i++;
	while (str[i] == '-' && str[i + 1] == 'n' && str[i + 2] == ' ')
	{
		i += 3;
	}
	return (i);
}

int	ret_between_quotes(char *str, int i)
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

char	*cut_addlist(char *str, int j, int i, t_list2 **t)
{
	char	*arg;

	arg = ft_strcut(str, j, i);
	ft_lstadd_backk(t, ft_lstneww(arg, arg));
	return (arg);
}

void	*pwd(void)
{
	char	*str;

	str = malloc(100);
	str = getcwd(str, 100);
	g_exit = 0;
	return (str);
}

void	ft_exit(void)
{
	exit(0);
}
