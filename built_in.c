#include "minishell.h"

void	cd(char *str, char **envp)
{
	int	i;
	char	*path;

	i = 0;
	if (!str)
	{
		while (envp[i])
    	{
    	    if(ft_strnstr(envp[i],"HOME=",ft_strlen(envp[i])) != 0)
    	        path = ft_substr(envp[i],5,ft_strlen(envp[i]));
    	    i++;
    	}
		if (chdir(path) != 0)
			printf("cd: HOME not set\n");
	}
	else if (chdir(str) != 0)
		printf("cd: no such file or directory: %s\n", str);
}

void	*pwd()
{
	char	*str;

	str = malloc(100);
	str = getcwd(str, 100);
	return (str);
}

void	ft_exit()
{
	exit(0);
}

void	ft_echo(char **str)
{
	if (str[1][0] == '-' && str[1][1] == 'n' && str[1][2] == '\0')
		printf("%s", str[2]);
	else
		printf("%s\n", str[1]);
}

void	ft_env(t_data *t)
{
	t_list2 *node;
	node = t->env_list;

	while (node)
	{
		printf("%s=%s\n", node->name, node->value);
		node = node->next;
	}
}

int	is_in_node(t_list2 *t, char *name, char *arg)
{
	t_list2	*p;

	p = t;
	while (p)
	{
		if (!ft_strcmp(p->name, name))
		{
			p->value = arg;
			return (1);
		}
		p = p->next;
	}
	return (0);
}

void	export(char *arg, t_data *t)
{
	int		i;
	char	**splited;
	t_list2 *p;
	t_list2 *node;

	node = t->env_list;
	i = 0;
	if (!arg)
	{
		while (node)
		{
			printf("declare -x %s=%s\n", node->name, node->value);
			node = node->next;
		}
	}
	else
	{
		splited = ft_split(arg, '=');
		if (is_in_node(t->env_list, splited[0], splited[1]))
			return ;
		p = ft_lstneww(splited[0], splited[1]);
		ft_lstadd_backk(&t->env_list, p);
	}
}

void	unset(char *arg, t_data *t)
{
	t_list2 *node;

	node = t->env_list;
	if (node && !node->next)
	{
		free(node);
		t->env_list = NULL;
		return ;
	}
	while (node)
	{
		if (!ft_strcmp(node->next->name, arg))
			node->next = node->next->next;
		node = node->next;
	}
}