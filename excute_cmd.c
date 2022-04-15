#include "minishell.h"
 
char *cmd_found(int count ,char **split_p,char *cmd)
{
    int i;
    DIR *dir;
    struct dirent *entry;

    i = 0;
    while (i < count)
    {
        if ((dir = opendir(split_p[i])) == NULL)
            printf("ERROR");
        else
        { 
            while ((entry = readdir(dir)) != NULL)
            {
                if(ft_strcmp(entry->d_name, cmd) == 0)
                {
                    return split_p[i];
                }
            }
        }
        closedir(dir);
        i++;
    }
    return 0;
}


void execut_cmd(char *path,char **cmd,char *command)
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
        i++;
    }
    parmList[i] = NULL;
    i = fork();
    if (i == 0)
	{
        execve(full_path, parmList, NULL);
		exit(0);
	}
    else
        wait(&i);
}

