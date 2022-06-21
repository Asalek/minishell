/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:28:22 by asalek            #+#    #+#             */
/*   Updated: 2022/06/03 16:34:17 by asalek           ###   ########.fr       */
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
# include <fcntl.h>
# include<errno.h> 
# define PROMPT "\033[0;36mPhoenix>\033[0m\033[0;37m"

int	g_exit;

typedef struct s_data
{
	char				*command;
	char				**commands;
	char				*cmd;
	char				*str;
	char				*str2;
	char				*temp;
	char				*file;
	char				*f1;
	char				*op;
	int					j;
	int					f[2];
	int					z;
	int					m;
	int					x;
	int					len;
	char				**envp;
	char				**split_path;
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
char	*cmd_found_2(int count, char **split_p, char **cmd);
void	file_sys_red(char *cmd, t_data *t);
int		command_found(char *cmd, t_data *t);
void	free_dp_1(char **ptr);
int		append_red(char *line, t_data *t);
int		input_red_(char *line, int x, t_data *t);
int		in_put_red(t_data *t, char *file);
int		input_red(char *line, t_data *t);
int		appe_nd_red(char *line, int x, t_data *t);
int		output_red(char *line, t_data *t);
void	execut_cmd_2(char *path, char **cmd, char *command, t_data *t);
void	execute_path_2(t_data *t, char **split_p, char **cmd_split, char *cmd);
void	ft_free(char **dd);
void	execut_built(char *cmd, t_data *t);
int		if_is_bult(char *cmd, t_data *t);
void	rdirect_1(char *line, t_data *t);
void	execut_red_bult(char *line, t_data *t);
void	red_file_sys(char *line, t_data *t);
void	redirect_files(char *line, t_data *t);
int		red_herd(char *line, t_data *t);
void	c_all_herdoc(char *line, int i, t_data *t, int x);
int		call_herdoc_(char *line, t_data *t);
int		call_herdoc(char *line, t_data *t);
void	herdoc_call(char *line, t_data *t);
int		is_echo(char *line);
int		check_single_quots(char *line, t_data *t);
int		check_double_quots(char *line, t_data *t);
int		check_single(char *line, t_data *t);
int		check_double(char *line, t_data *t);
int		check_qouts_(char *line, t_data *t);
void	collect_cmd(char *line, t_data *t);
void	complete_cmd(char *line, t_data *t);
void	fill_2(int x, int i, t_data *t);
void	fill_1(int x, int i, t_data *t);
void	comple_te_cmd(char *line, t_data *t);
void	collect_cmd(char *line, t_data *t);
int		count_herdoc(char *line, t_data *t);
int		return_i(char *line);
int		che_ckspace(char *line);
int		red_parssing(char *line);
int		red_parss(char *line);
void	reverse_cmd(char *line, t_data *t);
void	redirection(char *line, t_data *t);
int		count_er(char *line);
void	hendl_two(char *line, int i);
void	hendl_one(char *line, int i);
void	redairection_1(t_echo *e);
char	*line_handle(char *line, t_echo *e, t_data *t);//
int		check_if_is_echo(char *line);
int		check_2(char *line, t_echo *e, t_data *t);
int		check_qouts_echo(char *line, t_echo *e);
int		hendl_1(char *str, int i);
int		check_qouts(char *line, t_echo *e);
char	*replace_arg_env(char *str, t_data *t);
char	*cmd_found(int count, char **split_p, char **cmd);
void	execut_cmd(char *path, char **cmd, char *command, t_data *t);
void	init_func(char **envp);
int		check_quots(char *cmd);
t_list2	*creat_list(char **str);
t_list2	*ft_lstneww(char *v_name, char *v_value);
void	ft_lstadd_backk(t_list2 **lst, t_list2 *new);
int		more_built_in(char **cmd, t_data *t, char *line);
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
void	create_files(char *line, t_data *t);
void	unset(char *arg, t_data *t);
void	export(char *arg, t_data *t, char *line);
void	cd(char *str, char **envp);
void	pwd(void);
void	ft_exit(void);
void	exit_shell(int a);
void	execute_path(t_data *t, char **split_p, char **cmd_split, char *cmd);
t_list2	*echo_quotes(char *str);
char	*cut_addlist(char *str, int j, int i, t_list2 **t);
int		ret_between_quotes(char *str, int i);
int		skip_n(char *str);
char	*ft_strcutt(char *str, int start, int end);
char	**split_pipe(char *str);
void	remove_spaces(char *str);
int		quotes(char *str, int i);
int		check_pipe_inside_quotes(char *str);
void	remove_space_quotes(char **cmd_split);
int		unclosed_quotes(char *str);
void	check_redirection(char *cmd, t_data *t);
int		check_quots_pipe(char *cmd);
int		chech_export(char *str);
int		check_spaces(char *str);
int		check_export_arg(t_data *a, char *line, t_data *t);
int		is_in_node(t_list2 *t, char *name, char *arg);

//free

void	free_dp(char **ptr);
void	free_pointer(char *str);
void	free_all(char *str, char **tab, t_list2 *t);
void	free_all_2(char *s, char *s1, char **str, char **tab);

#endif