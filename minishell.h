#ifndef MINISHELL_H
#define MINISHELL_H



#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<readline/readline.h>
#include<readline/history.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "libft/libft.h"

typedef struct s_data
{
	char	**envp;
	struct s_linkedlist	*env_list;
}	t_data;

typedef struct s_linkedlist
{
	char	*name;
	char	*value;
	struct s_linkedlist	*next;
}	t_list2;



// start of excute commands


// int check_line(char *str,char **envp);
char *cmd_found(int count ,char **split_p,char *cmd);
void execut_cmd(char *path,char **cmd,char *command);
void init_func(char **envp);

// end of excute commands

t_list2	*creat_list(char **str);

// start of split path
char **split_path(char *string);
char *return_path(char **envp);

// libft
char *concatenate_string(char *original, char *add);
size_t	count_words(char const *s, char c);

void	cd(char *str, char **envp);
void	*pwd();
void	ft_exit();
void	ft_echo(char **str);
void	ft_env(char **envp);
#endif