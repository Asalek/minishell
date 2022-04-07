#include "minishell.h"

void	cd(char *str)
{
	if (chdir(str) != 0)
		printf("cd: no such file or directory: %s", str);
}

void	*pwd()
{
	char	*str;

	str = malloc(100);
	str = getcwd(str, 100);
	return (str);
}

void	ft_exit(int i)
{
	exit(i);
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