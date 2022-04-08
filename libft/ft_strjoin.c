/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:17:54 by asalek            #+#    #+#             */
/*   Updated: 2021/11/05 10:18:59 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = -1;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = (char *)malloc(((len1 + len2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[++i] != '\0')
		s3[i] = s1[i];
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
