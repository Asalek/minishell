/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:28:41 by asalek            #+#    #+#             */
/*   Updated: 2022/05/20 20:28:42 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_path(char *string)
{
	char	**path;

	if (string == NULL)
		return (NULL);
	path = ft_split(string, ':');
	return (path);
}

char	*return_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])) != 0)
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	if (!path)
		return (NULL);
	return (path);
}

char	*concatenate_string(char *original, char *add)
{
	int		i;
	int		j;
	char	*alloc1;

	alloc1 = malloc(sizeof(char) * (ft_strlen(original) + ft_strlen(add) + 1));
	i = 0;
	j = 0;
	while (original[j])
	{
		alloc1[j] = original[j];
		j++;
	}
	while (add[j])
	{
		alloc1[j] = add[i];
		i++;
		j++;
	}
	alloc1[j] = '\0';
	return (alloc1);
}
