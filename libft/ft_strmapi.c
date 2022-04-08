/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:08:29 by asalek            #+#    #+#             */
/*   Updated: 2021/11/07 15:12:04 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
