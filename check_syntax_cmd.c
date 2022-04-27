#include "minishell.h"




int check_3(char *line,t_echo *e)
{
    if (ft_strnstr(line,"echo",ft_strlen(line)))
    {
        if(check_qouts_echo(line,e) == 0) 
        {
            {
                printf("invalid syntax quots\n");
                return 0;
            }  
        }
    }
        else
        {
            if(check_qouts(line,e) == 0) 
            {
                printf("invalid syntax quots\n");
                return 0;
            }
        }
    return 1;
}

int check_2(char *line,t_echo *e,int i, t_data *t)
{
    e->parssing = ft_split(line,'|');
    while (e->parssing[i])
    {
        if (ft_strnstr(e->parssing[i],"echo",ft_strlen(e->parssing[i])))
        {
            if(check_qouts_echo(e->parssing[i],e) == 0) 
            {
                printf("invalid syntax quots\n");
                return 0;
            }    
        }
        else
        {
            if(check_qouts(e->parssing[i],e) == 0) 
            {
                printf("invalid syntax quots\n");
                return 0;
            } 
        }
        i++;
    }
	e->len = 0;
	while (e->parssing[e->len])
		e->len++;
	if (e->len > 1)
		pipee(e, t);//Pipe_hundler(e, t);
    return 1;

}

int check_1(char *line,t_echo *e, t_data *t)
{ 
    if (ft_strnstr(line,"|",ft_strlen(line)))
    {
        if(check_2(line, e, 0, t) == 0)
            return 0;
        else
            return 1;
    }
    else
    {
        if (check_3(line,e) == 0)
            return 0;
    }

    return 1;

}


int redairection_handle(char *line)
{
    int r;
  
    if (ft_strnstr(line,"echo",ft_strlen(line)))
    {
        r = check_if_is_echo(line);
        if (r == 0)
        {
            printf("command not found\n");
            return 0;
        }
    }
    if(hendl_1(line,0) == 0)
        return 0;
    
    return 1;
}


char* line_handle(char *line,t_echo *e,t_data *t)
{
    int i;
    if (check_1(line,e, t) == 0)
        return 0;
    i = 0;
    if (ft_strnstr(line,"|",ft_strlen(line)))
    {
        while (e->parssing[i])
        {
            if (ft_strnstr(e->parssing[i],">",ft_strlen(line)) || ft_strnstr(e->parssing[i],"<",ft_strlen(line)) || ft_strnstr(line,"echo",ft_strlen(line)))
            {
                if(redairection_handle(e->parssing[i]) == 0)
                    return 0;
            }
            i++;
        }
        i = 0;
        while (e->parssing[i])
        {
            if (ft_strnstr(e->parssing[i],">",ft_strlen(line) == 0) && ft_strnstr(e->parssing[i],"<",ft_strlen(line) == 0) && ft_strnstr(line,"echo",ft_strlen(line) == 0))
                handl_line(e->parssing[i],t);
            else if (ft_strnstr(e->parssing[i],">",ft_strlen(line)) || ft_strnstr(e->parssing[i],"<",ft_strlen(line)) || ft_strnstr(line,"echo",ft_strlen(line)))
                redairection_1(e);
            i++;
        }
    }
    else
    {
        if(redairection_handle(line) == 0)
            return 0;
        handl_line(line,t);
        // redairection_2(line,e);
    }
    return "ok";
} 