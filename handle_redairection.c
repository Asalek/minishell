#include "minishell.h"

void hendl_two(char *line,int i)
{
    i = 0;
    (void)line;
    return ;
}
 
void hendl_one(char *line,int i)
{
    i =0;
    (void)line;
    return ;
}

void redairection_1(t_echo *e)
{
    printf("%s\n",e->parssing[0]);
}
