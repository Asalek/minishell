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
    // int t;
    // int t2;
    // char *temp;

    // i-=2;
    // t2 = i;
    // if (line[i] == ' ')
    // {
    //     while (line[i] == ' ')
    //         i--;
    // }
    // t = i;
    // while (line[i] != ' ')
    //     i--;
    // i+=1;
    // temp = ft_substr(line,i,t);
    // i = 0;
    // t = i;
    // while (temp[i] && temp[i] != ' ')
    //     i++;
    // temp = ft_substr(temp,t,i);
    // printf("%s\n",temp);
}

void redairection_1(t_echo *e)
{
    
    printf("%s\n",e->parssing[0]);
}
