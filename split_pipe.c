#include "minishell.h"

char    *ft_strcutt(char    *str, int start, int end)
{
    int        i;
    char    *string;

    i = start;
    while (i < end)
        i++;
    string = malloc(i + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (start < end)
    {
        string[i] = str[start];
        i++;
        start++;
    }
    string[i] = '\0';
    return (string);
}

int count_pipes(char *str)
{
    int i;
    int x;

    i = 0;
    x = 0;
    while(str[i])
    {
        if(str[i] == '|')
            x++;
        i++;
    }
    return (x);
}

int    quotes(char *str, int i)
{
    if(str[i] == '\'')
    {
        i++;
        while(str[i] != '\'')
            i++;
    }
    else if (str[i] == '\"')
    {
        i++;
        while(str[i] != '\"')
            i++;
    }
    return (i);
}

char    **split_pipe(char *str)
{
    int i;
    int j;
    int x;
    char    **splitted;

    i = 0;
    x = 0;
    j = 0;
    splitted = malloc(sizeof(char) * (count_pipes(str) + 2));
    while(str[i])
    {
        if(str[i] == '\'' || str[i] == '\"')
        {
            i = quotes(str, i) + 1; 
        }
        if (str[i] == '|')
        {
            splitted[x] = malloc(sizeof(char));
            splitted[x] = ft_strcutt(str, j, i);
            j = i + 1;
            x++;
        }
        if (str[i + 1] == '\0')
        {
            splitted[x] = malloc(sizeof(char));
            splitted[x] = ft_strcutt(str, j, i + 1);
            x++;
            splitted[x] = NULL;
        }
        i++;
    }
    i = 0;
    // while(splitted[i])
    // {
    //     printf("%s\n", splitted[i]);
    //     i++;
    // }
    return (splitted);
}