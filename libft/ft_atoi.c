/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:37:46 by asalek            #+#    #+#             */
/*   Updated: 2021/11/14 00:41:31 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_min_max_long(double n, int a)
{
	n = a * n;
	if (n > LONG_MAX)
		return (-1);
	if (n < LONG_MIN)
		return (0);
	return (n);
}

int	ft_atoi(const char	*str)
{
	int		i;
	int		j;
	int		a;
	double	n;

	i = 0;
	j = 0;
	a = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i++] == '-')
			a = -a;
		j++;
	}
	if (j > 1)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (check_min_max_long(n, a));
}
