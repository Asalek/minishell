#include "minishell.h"
 
char *cmd_found(int count ,char **split_p,char *cmd)
{
	int				i;
	DIR				*dir;
	struct dirent	*entry;

	i = 0;
	while (i < count)
	{
		if ((dir = opendir(split_p[i])) == NULL)
			return (NULL);
		else
		{ 
			while ((entry = readdir(dir)) != NULL)
			{
				if(ft_strcmp(entry->d_name, cmd) == 0)
				{
					return (split_p[i]);
				}
			}
		}
		closedir(dir);
		i++;
	}
	return (0);
}


void execut_cmd(char *path, char **cmd ,char *command, t_data *t)
{
	char	*full_path;
	int		word_count;
	int		i;
	char	**parmList;

	full_path = ft_strjoin(path, cmd[0]);
	word_count = count_words(command, ' ');
	i = 0;
	parmList = malloc(sizeof(char*) * word_count + 1);
	while (i < word_count)
	{
		parmList[i] = cmd[i];
		i++;
	}
	parmList[i] = NULL;
	i = fork();
	if (i == 0)
	{
		if (execve(full_path, parmList, t->envp) == -1)
			exit(0);
	}
	else
		wait(&i);
	g_exit = WEXITSTATUS(i);
}
