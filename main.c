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
			exit_status = 1;
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
		ft_echo(cmd, t);
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

void	check_quots(char *cmd)
{
	int		i;
	char	c;

	i = 0;
	if (*cmd == '\"' || *cmd == '\'')
	{
		while (cmd[i])
		{		
			c = cmd[i + 1];
			cmd[i] = c;
			i++;
		}
		i--;
		cmd[i - 1] = '\0';		
	}
}

void handl_line(char *cmd,t_data *t)
{
    char *path;
    char **split_p;
    int count;
    char *full_path;
	char **cmd_split;

    path = return_path(t->envp);
    count = count_words(path,':');
    split_p = split_path(path);
    cmd_split = ft_split(cmd,' ');
	while (*cmd == ' ')
		cmd++;
	if (built_in_functions(cmd_split, t))
		return ;
	else if (!strncmp("./", cmd, 2))
		execut_cmd("", cmd_split, cmd, t);
	else if (!strncmp("/", cmd, 1))
		execut_cmd("", cmd_split, cmd, t);
    else if ((full_path = cmd_found(count,split_p,cmd_split[0])) == 0)
	{
		printf("COMMAND NOT FOUND\n");
		exit_status = 127;
	}
    else
    {
        full_path = concatenate_string(full_path, "/");		
        execut_cmd(full_path,cmd_split,cmd, t);
    }
}

int check_line(char *str,t_data *t,t_echo *e)
{
    e->l = 0;
    e->i = 0;
	if (ft_strlen(str) < 1)
		return (0);
	check_quots(str);
    if(line_handle(str,e,t) == NULL)
        return 0;
    return 1;
}

void	exit_shell(int a)
{
	(void)a;
	return ;
}

int main(int argc, char **argv, char **envp)
{
    char *line;
	(void)argc;
	(void)argv;
	t_list2	*list;
	t_data	t;
	t_echo strc;
    t_echo *e = &strc;

	list = creat_list(envp);
	t.envp = envp;
	t.env_list = list;
	line = readline(PROMPT);//\033[0;36mPhoenix>\033[0m\033[0;37m
    while (line)
	{
		signal(2, exit_shell);
		if (ft_isprint(line[0]))
			add_history(line);
		check_line(line,&t,e);
		free(line);
		line = readline(PROMPT);
	}
}
