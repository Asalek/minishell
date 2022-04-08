/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:51:10 by asalek            #+#    #+#             */
/*   Updated: 2021/11/12 01:13:51 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*str, int c)
{
	char	*str_end;

	str_end = (char *)str + ft_strlen(str);
	while (str_end > str && *str_end != (char)c)
		str_end--;
	if (*str_end == (char)c)
		return ((char *)str_end);
	return (NULL);
}
