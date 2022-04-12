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
			printf("cd: HOME not set");
	}
	else if (chdir(str) != 0)
		printf("cd: no such file or directory: %s", str);
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

void	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}