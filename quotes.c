/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:19:06 by asalek            #+#    #+#             */
/*   Updated: 2022/06/01 20:56:25 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_quotes(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str[0] == '\'' && str[len - 1] == '\'')
		return (1);
	else if (str[0] == '\"' && str[len - 1] == '\"')
		return (2);
	else
		return (0);
}

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
			printf("%s", p->value);
			return (p->value);
		}
		p = p->next;
	}
	return ("");
}
