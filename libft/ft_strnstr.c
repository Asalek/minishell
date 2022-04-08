/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:43:49 by asalek            #+#    #+#             */
/*   Updated: 2021/11/12 01:38:20 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	size_t	n;

	n = ft_strlen((char *)needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len-- >= n)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, n) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
