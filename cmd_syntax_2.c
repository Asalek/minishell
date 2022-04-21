#include "minishell.h"



static int check_single_quots(char *line,t_echo *e)
{
    int t;

    t = e->i;
    e->i++;
    while (line[e->i] && line[e->i] != '\'')
        e->i++;
    if (line[e->i] == '\'')
        return 1;
    else
        return 0;
}
static int check_double_quots(char *line,t_echo *e)
{
    int t;

    t = e->i;
    e->i++;
    while (line[e->i] && line[e->i] != '"')
        e->i++;
    if (line[e->i] == '"')
        return 1;
    else
        return 0;

}
static int check_single(char *line,t_echo *e)
{
    int t;

    t = e->i;
    e->i++;
    while (line[e->i] && line[e->i] != '\'' && line[e->i] != ' ')
        e->i++;
    if (line[e->i] == '\'')
        return 1;
    else
        return 0;
}
static int check_double(char *line,t_echo *e)
{
    int t;

    t = e->i;
    e->i++;
    while (line[e->i] && line[e->i] != '"' && line[e->i] != ' ')
        e->i++;
    if (line[e->i] == '"')
        return 1;
    else
        return 0;

}

int check_qouts(char *line,t_echo *e)
{
    e->i = 0;
    while (line[e->i])
    {
        if (line[e->i] == '\'')
        {
            if (check_single(line,e) == 0)
                return 0;           
        }
        else if (line[e->i] == '"')
        {
            if (check_double(line,e) == 0)
                return 0;
        }
        e->i++;
    }
    return 1;
}


int check_qouts_echo(char *line,t_echo *e)
{
    e->i = 0;
    while (line[e->i])
    {
        if (line[e->i] == '\'')
        {
            if (check_single_quots(line,e) == 0)
                return 0;           
        }
        else if (line[e->i] == '"')
        {
            if (check_double_quots(line,e) == 0)
                return 0;
        }
        e->i++;
    }
    return 1;
}