/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:47:23 by asalek            #+#    #+#             */
/*   Updated: 2021/11/10 18:30:03 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	free_unallocated_tab(char	*str)
{
	if (!str)
		free(str);
}

int	how_much_words(char const *str, char c)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			x++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (x);
}

char	*allocate_new_tab(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

int	word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		jj;
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (how_much_words(s, c) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < how_much_words(s, c))
	{
		jj = 0;
		str[i] = allocate_new_tab(word_len(&s[j], c) + 1);
		free_unallocated_tab(str[i]);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][jj++] = s[j++];
		str[i][jj] = '\0';
	}
	str[i] = NULL;
	return (str);
}
