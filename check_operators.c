#include "minishell.h"

static int handl_op_2(char *str,int i)
{
    int t;

    t = i;// 5
    i++;
    while (str[i] == '<')
        i++;
    if (i - t != 1)
    {
        if (i - t != 2)
            return 0;   
    }  
    return 1; 
}

static int handl_op(char *str,int i)
{
    int t;

    t = i;// 5
    i++;
    while (str[i] == '>')
        i++;
    if (i - t != 1)
    {
        if (i - t != 2)
            return 0;   
    }  
    return 1; 
}

int hendl_1(char *str,int i)
{
    while (str[i])
    {
        if (str[i] == '>')
        { 
            if(handl_op(str,i) == 0)
            {
                printf("parse error near `>'\n");
                return 0;
            }
        } 
        else if (str[i] == '<') 
        {
            if(handl_op_2(str,i) == 0)
            {
                printf("parse error near `<'\n");
                return 0;
            }
        }   
        i++;
    }
    return 1;
}