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

typedef struct s_data
{
	char	**envp;
	struct s_linkedlist	*list;
}	t_data;

typedef struct s_linkedlist
{
	char	*name;
	char	*value;
	struct s_linkedlist	*next;
}	t_list;

typedef struct s_command
{
	char	*cmd;
	char	*arg;
	struct s_command	*next;
}	t_command;



// start of excute commands


// int check_line(char *str,char **envp);
char *cmd_found(int count ,char **split_p,char *cmd);
void execut_cmd(char *path,char **cmd,char *command);
void init_func(char **envp);

// end of excute commands



// start of split path
char **split_path(char *string);
char *return_path(char **envp);

// libft
char *concatenate_string(char *original, char *add);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_toupper(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strnstr(const char *s, const char *find, size_t len);
int	ft_toupper(int c);
char	*ft_strrchr(const char	*str, int c);
int	ft_tolower(int c);
int		ft_strcmp(char *s1, char *s2);
size_t	count_words(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int	ft_isdigit(int c);
int	ft_isalpha(int c);
int	ft_atoi(const char *str);
int	ft_isprint(int c);

void	cd(char *str);
void	*pwd();
void	ft_exit();
void	ft_echo(char **str);
void	ft_env(char **envp);
#endif