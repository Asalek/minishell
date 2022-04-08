/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:36:29 by asalek            #+#    #+#             */
/*   Updated: 2021/11/10 18:42:32 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	size_t			i;

	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr[i] != ptr2[i])
			return ((unsigned char)ptr[i] - (unsigned char)ptr2[i]);
		i++;
	}
	return (0);
}
