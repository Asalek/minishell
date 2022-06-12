#include "minishell.h"

int check_pipe_inside_quotes(char *str)
{
    int     i;
    int     j;
    char    c;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == '\'' || str[i] == '"')
        {
            c = str[i];
            i++;
            while (str[i] != c)
                i++;
        }
        else if (str[i] == '|')
            return (1);
        i++;
    }
    return (0);
}
