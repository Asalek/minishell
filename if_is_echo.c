
#include "minishell.h"

static int handle_2(char *line,int i)
{
    int t;
    char *sub;

    t = i;
   
    i++;
    while (line[i] != '"' && line[i])
        i++;
    if (line[i] == '"')
    {
        
        sub = ft_substr(line,t,(i - t) + 1);
        if (ft_strcmp("\"echo\"",sub) == 0)
            return (i - t) + 1;
    }
    return 0;
    
}
static int handle_1(char *line,int i)
{
    int t;
    char *sub;

    t = i;
    if (line[i] == '\'')
    {
        i++;
        while (line[i] != '\'' && line[i])
            i++;
        if (line[i] == '\'')
        {
            sub = ft_substr(line,t,(i - t) + 1);
            if (ft_strcmp("'echo'",sub) == 0)
                return 1;
        }
        else
            return 0;
    }
    return handle_2(line,i);
}

int check_if_is_echo(char *line)
{
    int i;
    int t;
    char *sub;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (line[i] == '\'' || line[i] == '"')
    {
        i = handle_1(line,i);
        if (i == 0)
            return 0;
        else
            return i;
    }
    t = i;
    while (ft_isalpha(line[i]) && line[i])
    {
        if (line[i] == ' ')
            break;
        i++;
    }
    sub = ft_substr(line,t,i - t);
    if (ft_strcmp("echo",sub) == 0)
        return i - t;
    else
        return 0;
}