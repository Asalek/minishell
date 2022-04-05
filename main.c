#include "minishell.h"


 
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

    
    if ((full_path = cmd_found(count,split_p,cmd_split[0])) == 0)
        printf("COMMAND NOT FOUND\n");
    else
    {
        full_path = concatenate_string(full_path, "/");
        execut_cmd(full_path,cmd_split,cmd);
        // printf("TEST\n");
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
    handl_line(str,envp);
    return 1;
}

int main(int argc, char **argv, char **envp)
{
    
    char *line;

    while (1)
    {
        line = readline("\033[0;36mPhoenix >\033[0m");  
        if(line != NULL) 
        {
            if(check_line(line,envp) == 0)
                return 0;
            else
                free(line);   
        }
    }
    

        

}   

 