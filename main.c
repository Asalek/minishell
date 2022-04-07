#include "minishell.h"

int	built_in_functions(char **cmd, char **envp)
{
	if (!ft_strcmp(cmd[0], "cd"))
	{
		cd(cmd[1]);
		return (1);
	}
	if (!ft_strcmp(cmd[0], "pwd"))
	{
		printf("%s\n", pwd());
		return (1);
	}
	if (!ft_strcmp(cmd[0], "exit"))
		ft_exit();
	if (!ft_strcmp(cmd[0], "echo"))
	{
		ft_echo(cmd);
		return (1);
	}
	if (!ft_strcmp(cmd[0], "env"))
	{
		ft_env(envp);
		return (1);
	}
	return 0;
}

void handl_line(char *cmd,char **envp)
{
    char *path;
    char **split_p;
    int count;
    char *full_path;

    path = return_path(envp);
    count = count_words(path,':');
    split_p = split_path(path);
    
    char **cmd_split = ft_split(cmd,' ');

	if (built_in_functions(cmd_split, envp))
			return ;
    if ((full_path = cmd_found(count,split_p,cmd_split[0])) == 0)
        printf("COMMAND NOT FOUND\n");
    else
    {
        full_path = concatenate_string(full_path, "/");		
        execut_cmd(full_path,cmd_split,cmd);
    }
}

int check_line(char *str,char **envp)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] == '\'')
        {
            return 0;
        }
        else if(str[i] == '"')
        {
            return 0;
        }
        i++;
    }
    if (i == 0)
        return 0;
    
    handl_line(str,envp);
    return 1;
}

int main(int argc, char **argv, char **envp)
{
    char *line;

    while (1)
        if((line = readline(">")) != NULL)
        {
			if (ft_isprint(line[0]))
				add_history(line);
            if(check_line(line,envp) == 0)
				line = readline(">");
            else
                free(line);
        }
}
