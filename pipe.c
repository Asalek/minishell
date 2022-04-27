#include "minishell.h"

void execut_cmdd(char *path,char **cmd,char *command, t_data *t)
{
    char *full_path;
    int word_count;
    int i;
    char **parmList;

    full_path = ft_strjoin(path,cmd[0]);
    word_count = count_words(command,' ');// ls -l
    i = 0;
    parmList = malloc(sizeof(char*) * word_count + 1);
    while (i < word_count)
    {
        parmList[i] = cmd[i];
		check_quots(parmList[i]);
        i++;
    }
    parmList[i] = NULL;
    if (execve(full_path, parmList, t->envp) == -1)
		exit(0);
}

void handl_linee(char *cmd,t_data *t)
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
		execut_cmdd("", cmd_split, cmd, t);
	else if (!strncmp("/", cmd, 1))
		execut_cmdd("", cmd_split, cmd, t);
    else if ((full_path = cmd_found(count,split_p,cmd_split[0])) == 0)
	{
		printf("COMMAND NOT FOUND\n");
		exit_status = 127;
	}
    else
    {
        full_path = concatenate_string(full_path, "/");		
        execut_cmdd(full_path,cmd_split,cmd, t);
    }
}

void	Pipe_hundler(t_echo *e, t_data *t)
{
	int id;
	int id2;
	if (pipe(t->fd) == -1)
		return ;
	id = fork();
	if(id == 0)
	{
		dup2(t->fd[1], STDOUT_FILENO);
		close(t->fd[0]);
		close(t->fd[1]);
		handl_linee(e->parssing[0], t);
	}
	id2 = fork();
	if(id2 == 0)
	{
		dup2(t->fd[0], STDIN_FILENO);
		close(t->fd[0]);
		close(t->fd[1]);
		handl_linee(e->parssing[1], t);
	}
	e->i += 2;
	close(t->fd[0]);
	close(t->fd[1]);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
}
