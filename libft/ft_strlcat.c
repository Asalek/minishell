/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:24:37 by asalek            #+#    #+#             */
/*   Updated: 2021/11/12 01:24:45 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	dest_s;

	src_size = ft_strlen(src);
	dest_s = ft_strlen(dst);
	if (dstsize < dest_s)
		return (src_size + dstsize);
	else
	{
		dst = dst + dest_s;
		ft_strlcpy(dst, src, dstsize - dest_s);
		return (src_size + dest_s);
	}
}	
