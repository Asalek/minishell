#include "minishell.h"

int	more_built_in(char **cmd, t_data *t)
{
	if (!ft_strcmp(cmd[0], "export"))
	{
		export(cmd[1], t);
		return (1);
	}
	if (!ft_strcmp(cmd[0], "unset"))
	{
		if (!cmd[1])
		{
			printf("unset: not enough arguments\n");
			return (1);
		}
		unset(cmd[1], t);
		return (1);
	}
	else
		return (0);
}

int	built_in_functions(char **cmd, t_data *t)
{
	if (!ft_strcmp(cmd[0], "cd"))
	{
		cd(cmd[1], t->envp);
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
		ft_env(t);
		return (1);
	}
	else	
		return more_built_in(cmd, t);
}

void handl_line(char *cmd,t_data *t)
{
    char *path;
    char **split_p;
    int count;
    char *full_path;

    path = return_path(t->envp);
    count = count_words(path,':');
    split_p = split_path(path);
    
    char **cmd_split = ft_split(cmd,' ');

	if (built_in_functions(cmd_split, t))
		return ;
    else if ((full_path = cmd_found(count,split_p,cmd_split[0])) == 0)
        printf("COMMAND NOT FOUND\n");
    else
    {
        full_path = concatenate_string(full_path, "/");		
        execut_cmd(full_path,cmd_split,cmd);
    }
}

int check_line(char *str,t_data *t)
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
    
    handl_line(str,t);
    return 1;
}

int main(int argc, char **argv, char **envp)
{
    char *line;
	(void)argc;
	(void)argv;
	t_list2	*list;
	t_data	t;

	list = creat_list(envp);
	t.envp = envp;
	t.env_list = list;
    while (1)
        if((line = readline(">")) != NULL) //\033[0;36mPhoenix>\033[0m\033[0;37m
        {
			if (ft_isprint(line[0]))
				add_history(line);
            check_line(line,&t);
    		free(line);
        }
}
