#ifndef MINISHELL_H
#define MINISHELL_H

int	exit_status;


#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<readline/readline.h>
#include<readline/history.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include "libft/libft.h"

#define PROMPT "\033[0;36mPhoenix>\033[0m\033[0;37m"

typedef struct s_data
{
	char	**envp;
	int		id;
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
t_list2	*ft_lstneww(char *v_name, char *v_value);
void	ft_lstadd_backk(t_list2 **lst, t_list2 *new);

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
void	ft_env(t_data *t);
void	unset(char *arg, t_data *t);
void	export(char *arg, t_data *t);
#endif