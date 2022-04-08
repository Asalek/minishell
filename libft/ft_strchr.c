/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:45:37 by asalek            #+#    #+#             */
/*   Updated: 2021/11/12 01:01:38 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	if (*str == (char)ch)
		return ((char *)str);
	return (NULL);
}
