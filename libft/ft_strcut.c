/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:29:09 by asalek            #+#    #+#             */
/*   Updated: 2022/06/03 17:17:34 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char	*str, int start, int end)
{
	int		i;
	char	*string;

	i = start;
	while (i < end)
		i++;
	string = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		string[i] = str[start];
		i++;
		start++;
	}
	string[i] = '\0';
	return (string);
}
