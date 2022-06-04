/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:28:15 by asalek            #+#    #+#             */
/*   Updated: 2022/06/04 20:30:37 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list2	*echo_quotes(char *str)
{
	int		i;
	int		j;
	char	*arg;
	t_list2	*t;

	t = NULL;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0' && j < i && i > 0)
			arg = cut_addlist(str, j, i, &t);
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (j < i && i > 0)
				arg = cut_addlist(str, j, (i - 1), &t);
			j = i;
			i = ret_between_quotes(str, i);
			arg = cut_addlist(str, j, i, &t);
			j = i + 1;
		}	
		i++;
	}
	return (t);
}

int	double_quote(int j, char *p, t_data *t)
{
	int		i;
	char	*env;

	i = 0;
	if (p[j] == '$')
	{
		j++;
		env = malloc(ft_strlen(p) * sizeof(char));
		i = 0;
		while (ft_isalpha(p[j]) || p[j] == '_' || p[j] == '?')
		{
			env[i] = p[j];
			i++;
			j++;
		}
		env[i] = '\0';
		ft_putstr_fd(replace_arg_env(env, t), 1);
		free(env);
		j--;
	}
	else
		if (p[j] != '\\')
			ft_putchar_fd(p[j], 1);
	return (j);
}

int	replace_word(char *str, int i, t_data *t)
{
	char	*s;
	int		j;

	j = 0;
	if (str[i] == '$')
	{
		i++;
		s = malloc(ft_strlen(str) * sizeof(char));
		while (str[i] != '\'' && str[i] != '\"'
			&& str[i] != '\0' && str[i] != ' ')
		{
			s[j] = str[i];
			j++;
			i++;
		}
		s[j] = '\0';
		ft_putstr_fd(replace_arg_env(s, t), 1);
	}
	else
		printf("%c", str[i]);
	return (i);
}

void	echo_exec(char *p, char *str, t_data *t)
{
	int		j;

	j = 0;
	while (p[j] != '\0')
	{
		if (p[j] == '\'')
		{
			j++;
			while (p[j] != '\'')
				ft_putchar_fd(p[j++], 1);
		}
		else if (p[j] == '\"')
		{
			j++;
			while (p[j] && p[j] != '\"')
			{
				j = double_quote(j, p, t);
				j++;
			}
		}
		else if (p[j] != '\\')
			j = replace_word(p, j, t);
		j++;
	}
}

void	ft_echo(char *str, t_data *t)
{
	int		n;
	t_list2	*p;

	n = 0;
	if (!ft_strncmp(str, "echo ", 5))
		str = ft_strcut(str, 5, ft_strlen(str));
	n = skip_n(str);
	str = ft_strcut(str, n, ft_strlen(str));
	p = echo_quotes(str);
	while (p)
	{
		echo_exec(p->value, str, t);
		p = p->next;
	}
	if (n == 0)
		printf("\n");
	g_exit = 0;
}
