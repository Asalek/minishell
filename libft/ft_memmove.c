/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:11:56 by asalek            #+#    #+#             */
/*   Updated: 2021/11/12 00:16:30 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *sr, size_t len)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	i = 0;
	if (!dst && !sr)
		return (NULL);
	dest = (unsigned char *)dst;
	src = (unsigned char *)sr;
	if (src < dest)
	{
		while (i++ < len)
			dest[len - i] = src[len - i];
	}
	else
	{
		while (len-- > 0)
			*(dest++) = *(src++);
	}
	return (dst);
}
