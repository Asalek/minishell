/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitl_in_additional.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:44:13 by asalek            #+#    #+#             */
/*   Updated: 2022/06/01 15:01:13 by asalek           ###   ########.fr       */
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

char	*ft_strcut(char	*str, int start, int end)
{
	int		i;
	char	*string;

	i = start;
	while (i < end)
		i++;
	string = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		string[i] = str[start];
		i++;
		start++;
	}
	return (string);
}

t_list2	*echo_quotes(char *str)
{
	int	i;
	int	j;
	char	c;
	char	**splited;
	char	*arg;
	t_list2 *t;
	t = NULL;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0' && j < i && i > 0)
		{
			if (str[j] == '\\')
				j++;
			arg = ft_strcut(str, j , i + 1);
			ft_lstadd_backk(&t, ft_lstneww(arg, arg));
		}
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (j < i && i > 0)
			{
				arg = ft_strcut(str, j , i);
				ft_lstadd_backk(&t, ft_lstneww(arg, arg));
			}
			j = i;
			if (str[i] == '\'')
			{
				i++;
				while (str[i] != '\'')
					i++;
			}
			else if (str[i] == '\"')
			{
				i++;
				while (str[i] != '\"')
					i++;
			}
			arg = ft_strcut(str, j , i + 1);
			ft_lstadd_backk(&t, ft_lstneww(arg, arg));
			j = i + 1;
		}	
		i++;
	}
	return (t);
}

void	ft_echo(char *str, t_data *t)
{
	int	i;
	int	n;
	t_list2	*p;

	i = 0;
	n = 0;
	if (!str)
		printf("\n");
	if (!ft_strncmp(str, "echo ", 5))
		str = ft_strtrim(str + 5, str + ft_strlen(str));
	n = skip_n(str);
	str = ft_strtrim(str + n, str + ft_strlen(str));
	p = echo_quotes(str);
	while (p)
	{
		printf("%s\n", p->value);
		p = p->next;
	}
	
	if (n == 0)
		printf("\n");
	/*
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
	}*/
	g_exit = 0;
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
