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
			g_exit = 1;
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
	int		len;

	len=ft_strlen(cmd);
	i = 0;
	if ((*cmd == '\"' && cmd[len - 1] == '\"') 
		|| (*cmd == '\'' && cmd[len - 1] == '\''))
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
	if (!cmd || !ft_strncmp(cmd, "", 1))
		return ;	
	while (*cmd == ' ')
		cmd++;
	if (built_in_functions(cmd_split, t))
		return ;
	else if (!strncmp("./", cmd, 2))
		execut_cmd("", cmd_split, cmd, t);
	else if (!strncmp("/", cmd, 1))
		execut_cmd("", cmd_split, cmd, t);
    else if (cmd_found(count, split_p, cmd_split[0]) == 0)
	{
		command_not_found(1);
		printf("COMMAND NOT FOUND\n");
		g_exit = 127;
	}
    else
    {
		full_path = cmd_found(count,split_p,cmd_split[0]);
        full_path = concatenate_string(full_path, "/");		
        execut_cmd(full_path,cmd_split,cmd, t);
    }
}

int check_line(char *str,t_data *t,t_echo *e)
{
	char	*cmd;

    e->l = 0;
    e->i = 0;
	if (!strncmp(str, "$", 1))
	{
		str++;
		cmd = replace_arg_env(str, t);
		handl_line(cmd, t);
		return (0);
	}
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
	t_list2	*list;
	t_data	t;
	t_echo strc;
    t_echo *e = &strc;

	ft_strnstr(argv[0], ft_itoa(argc), 2);
	list = creat_list(envp);
	t.envp = envp;
	t.env_list = list;
	line = readline(PROMPT);
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
