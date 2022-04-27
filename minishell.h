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
	struct s_linkedlist	*env_list;
	int	bool_fd;
	int	fd[2];
}	t_data;

typedef struct s_linkedlist
{
	char	*name;
	char	*value;
	struct s_linkedlist	*next;
}	t_list2;

typedef struct echo_parssing{

    int i;
    int len;
    int j;
    int t;
    int r;
    int y;
    int l;
    char **alloc;
    char **parssing;
    char *line;

}t_echo;



// start of handle redairection


void hendl_two(char *line,int i);
void hendl_one(char *line,int i);
void redairection_1(t_echo *e);


// start of check syntax of command
char* line_handle(char *line,t_echo *e,t_data *t);

int check_if_is_echo(char *line);

int check_3(char *line,t_echo *e);
int check_2(char *line,t_echo *e,int i, t_data *t);
int check_1(char *line,t_echo *e, t_data *t);
int redairection_handle(char *line);
int check_qouts_echo(char *line,t_echo *e);
int hendl_1(char *str,int i);
int check_qouts(char *line,t_echo *e);

int	has_quotes(char *str);
char	*replace_arg_env(char *str, t_data *t);


char *cmd_found(int count ,char **split_p,char *cmd);
void execut_cmd(char *path,char **cmd,char *command, t_data *t);
void init_func(char **envp);
void	check_quots(char *cmd);

// end of excute commands

t_list2	*creat_list(char **str);
t_list2	*ft_lstneww(char *v_name, char *v_value);
void	ft_lstadd_backk(t_list2 **lst, t_list2 *new);
int	more_built_in(char **cmd, t_data *t);
int	built_in_functions(char **cmd, t_data *t);
void handl_line(char *cmd,t_data *t);
void	Pipe_hundler(t_echo *e, t_data *t);
void	pipee(t_echo *e, t_data *t);

// start of split path
char **split_path(char *string);
char *return_path(char **envp);

// libft
char *concatenate_string(char *original, char *add);
size_t	count_words(char const *s, char c);

//built-in functions

void	cd(char *str, char **envp);
void	*pwd();
void	ft_exit();
void	ft_echo(char **str, t_data *t);
void	ft_env(t_data *t);
void	unset(char *arg, t_data *t);
void	export(char *arg, t_data *t);
#endif