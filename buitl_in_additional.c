/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitl_in_additional.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:44:13 by asalek            #+#    #+#             */
/*   Updated: 2022/05/31 13:44:52 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' && str[i + 1] == 'n'&& str[i + 2] == ' ')
	{
		i += 3;
	}
	return (i);
}

void	echo_quotes(char *str)
{
	int	i;
	char	c;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			c = str[i];
			i++;
			while (str[i] != c)
			{
				printf("%c", str[i]);
			}
			
		}				
	}
}

void	ft_echo(char *str, t_data *t)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!ft_strncmp(str, "echo ", 5))
		str = ft_strtrim(str + 5, str + ft_strlen(str));
	n = skip_n(str);
	str = ft_strtrim(str + n, str + ft_strlen(str));
	echo_quotes(str);
	if (n > 0)
		printf("\n");
	/*if (!str[1])
		printf("\n");
	else if (has_quotes(str[1]) == 1)
	{
		check_quots(str[1]);
		printf("%s\n", str[1]);
	}
	else if (has_quotes(str[1]) == 2)
	{
		check_quots(str[1]);
		if (!strncmp(str[1], "$", 1))
		{
			str[1]++;
			printf("%s\n", replace_arg_env(str[1], t));
		}
		else
			printf("%s\n", str[1]);
	}
	else if (str[1][0] == '-' && str[1][1] == 'n' && str[1][2] == '\0')
		printf("%s", str[2]);
	else
	{
		if (!ft_strncmp(str[1], "$", 1))
		{
			str[1]++;
			printf("%s\n", replace_arg_env(str[1], t));
		}
		else
			printf("%s\n", str[1]);
	}
	g_exit = 0;*/
}

void	*pwd(void)
{
	char	*str;

	str = malloc(100);
	str = getcwd(str, 100);
	g_exit = 0;
	return (str);
}

void	ft_exit(void)
{
	exit(0);
}
