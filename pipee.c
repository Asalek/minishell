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
		exit(0);
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


int count(char **cmd)
{
	int i;
	i = 0;
	while (cmd[i])
		i++;
	return i;
}

void pipee(t_echo *e, t_data *t)
{
	int		x = 0;
	pid_t	pid;
	int		cmd_len = count(e->parssing);
	int		fd[2*cmd_len];

	e->i = 0;
	e->j = 0;
	while(e->i < cmd_len){
        if(pipe(fd + e->i*2) < 0)
		{
            perror("couldn't pipe");
            exit(EXIT_FAILURE);
        }
		e->i++;
    }
	while (e->parssing[x] != NULL)
	{

		if ((pid = fork()) == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (e->parssing[x + 1] != NULL)
			{
				if(dup2(fd[e->j + 1], 1) < 0)
					perror("dup2");
			}
			if (e->j != 0)
			{
				if(dup2(fd[e->j - 2], 0) < 0)
				{	
                    perror("dup");
				}
			}
			for(e->i = 0; e->i < 2 * cmd_len; e->i++){
                close(fd[e->i]);
            }
			handl_linee(e->parssing[x], t);
		}
		x++;
		e->j += 2;
	}
	for(e->i = 0; e->i < 2 * cmd_len; e->i++)
	{
        close(fd[e->i]);
    }
    for(e->i = 0; e->i < cmd_len; e->i++)
        wait(NULL);
}

/*

void	exec_first(char *e, t_data *t, int *fd)
{
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	handl_linee(e, t);
}
void	exec_mid(char *e, t_data *t, int *fd, int *fd2)
{
	dup2(fd2[0], 0);
	dup2(fd[1], 1);
	close(fd2[0]);
	close(fd2[1]);
	close(fd[0]);
	close(fd[1]);
	handl_linee(e, t);
}
void	exec_last(char *e, t_data *t,int *fd , int *fd2)
{
	dup2(fd2[0], 0);
	close(fd2[0]);
	close(fd2[1]);
	close(fd[0]);
	close(fd[1]);
	handl_linee(e, t);
}

void	pipee(t_echo *e, t_data *t)
{
	int	i = 0;
	int j = 0;

	while (e->parssing[i])
		i++;
	int fd[i][2];
	int	id[i];
	while (e->parssing[j])
	{
		pipe(fd[j]);
		id[j] = fork();
		if (id[j] == 0)
		{
			if (j == 0)
				exec_first(e->parssing[j], t, fd[j]);
			else if (j < i - 1)
				exec_mid(e->parssing[j], t, fd[j], fd[j - 1]);
			else
				exec_last(e->parssing[j], t, fd[j] , fd[j - 1]);
		}
		j++;
	}
	int f = i;
	int ff = 0;
	while (ff != i)
	{
		close(fd[ff][0]);
		close(fd[ff][1]);
		ff++;
	}
	while (f != 0)
	{
		wait(NULL);
		f--;
	}
	
}
*/