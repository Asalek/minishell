/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:28:22 by asalek            #+#    #+#             */
/*   Updated: 2022/05/31 20:56:20 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<readline/readline.h>
# include<readline/history.h>
# include <dirent.h>
# include <sys/types.h>
# include <string.h>
# include <signal.h>
# include "libft/libft.h"

# define PROMPT "\033[0;36mPhoenix>\033[0m\033[0;37m"

int	g_exit;

typedef struct s_data
{
	char				**envp;
	struct s_linkedlist	*env_list;
	int					bool_fd;
	pid_t				pid;
	int					i;
}	t_data;

typedef struct s_linkedlist
{
	char				*name;
	char				*value;
	struct s_linkedlist	*next;
}	t_list2;

typedef struct echo_parssing{
	int		i;
	int		len;
	int		j;
	int		t;
	int		r;
	int		y;
	int		l;
	char	**alloc;
	char	**parssing;
	char	*line;
}	t_echo;

void	hendl_two(char *line, int i);
void	hendl_one(char *line, int i);
void	redairection_1(t_echo *e);
char	*line_handle(char *line, t_echo *e, t_data *t);
int		check_if_is_echo(char *line);
int		check_3(char *line, t_echo *e);
int		check_2(char *line, t_echo *e, int i, t_data *t);
int		check_1(char *line, t_echo *e, t_data *t);
int		redairection_handle(char *line);
int		check_qouts_echo(char *line, t_echo *e);
int		hendl_1(char *str, int i);
int		check_qouts(char *line, t_echo *e);
int		has_quotes(char *str);
char	*replace_arg_env(char *str, t_data *t);
char	*cmd_found(int count, char **split_p, char *cmd);
void	execut_cmd(char *path, char **cmd, char *command, t_data *t);
void	init_func(char **envp);
void	check_quots(char *cmd);
t_list2	*creat_list(char **str);
t_list2	*ft_lstneww(char *v_name, char *v_value);
void	ft_lstadd_backk(t_list2 **lst, t_list2 *new);
int		more_built_in(char **cmd, t_data *t);
int		built_in_functions(char **cmd, t_data *t, char *cmdline);
void	handl_line(char *cmd, t_data *t);
void	Pipe_hundler(t_echo *e, t_data *t);
void	pipee(t_echo *e, t_data *t);
void	command_not_found(int i);
int		count(char **cmd);
char	**split_path(char *string);
char	*return_path(char **envp);
char	*concatenate_string(char *original, char *add);
size_t	count_words(char const *s, char c);
void	ft_echo(char *str, t_data *t);
void	ft_env(t_data *t);
void	unset(char *arg, t_data *t);
void	export(char *arg, t_data *t);
void	cd(char *str, char **envp);
void	*pwd(void);
void	ft_exit(void);
void	exit_shell(int a);
void	execute_path(t_data *t, char **split_p, char **cmd_split, char *cmd);
int		check_single_quots(char *line, t_echo *e);
int		check_double_quots(char *line, t_echo *e);

#endif