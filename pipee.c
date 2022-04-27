#include"minishell.h"

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
/*
void	pipee(t_echo *e, t_data *t)
{
	e->i = 0;
	e->j = 0;
	while (e->parssing[e->i])
		e->i++;
	int *id = malloc(e->i * sizeof(int));
	while (e->parssing[e->j])
	{
		if (pipe(t->fd) == -1)
			return ;
		id[e->j] = fork();
		if(id[e->j] == 0)
		{
			if (e->parssing[e->j + 1])
			{
				dup2(t->fd[1], 1);
				dup2(t->fd[0], 0);
				// close(t->fd[0]);
				// close(t->fd[1]);
				handl_linee(e->parssing[e->j], t);
			}
			else
			{
				dup2(t->fd[0], 0);
				// close(t->fd[0]);
				// close(t->fd[1]);
				handl_linee(e->parssing[e->j], t);
			}
		}
		else
		{
			close(t->fd[0]);
			close(t->fd[1]);
			wait(NULL);
		}
		e->j++;
	}
	
}
*/
void	pipee(t_echo *e, t_data *t)
{
	int	i = 0;
	int j = 0;

	while (e->parssing[i])
		i++;
	int fd[i - 1][2];
	int	id[i];
	while (e->parssing[j])
	{
		pipe(fd[j]);
		id[j] = fork();
		if (id[j] == 0)
		{
			if (j != 0)
				dup2(fd[j - 1][0], 0);
			dup2(fd[j][1], 1);
			close(fd[j][0]);
			close(fd[j][1]);
			handl_linee(e->parssing[j], t);
		}
		else
		{
			close(fd[j][0]);
			close(fd[j][1]);
			wait(NULL);
		}
		j++;
	}
}
