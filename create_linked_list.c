/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:19:04 by asalek            #+#    #+#             */
/*   Updated: 2022/05/20 17:19:05 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list2	*ft_lstneww(char *v_name, char *v_value)
{
	t_list2	*new;

	new = malloc(sizeof(t_list2));
	if (!new)
		return (NULL);
	new->name = v_name;
	new->value = v_value;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_backk(t_list2 **lst, t_list2 *new)
{
	t_list2	*temp;

	temp = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_list2	*creat_list(char **str)
{
	t_list2	*p;
	char	**splited;
	int		i;

	i = 0;
	p = NULL;
	while (str[i])
	{
		splited = ft_split(str[i], '=');
		ft_lstadd_backk(&p, ft_lstneww(splited[0], splited[1]));
		free(splited[0]);
		free(splited[1]);
		free(splited);
		i++;
	}
	return (p);
}
