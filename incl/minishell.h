/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:35:01 by mamuller          #+#    #+#             */
/*   Updated: 2022/02/27 14:35:01 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/incl/libft.h"
# include "../srcs/builtin/inc_pub/ft_builtin.h"
# include "../srcs/lexor/inc_pub/ft_lexor.h"
# include "../srcs/parser/inc_pub/ft_parser.h"
# include "../srcs/executor/inc_pub/executor.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <signal.h>
# include <dirent.h>
# include <sys/stat.h>

# define BUFFER_SIZE 1

# define SYMLINK 1
# define NOT_SYMLINK 0

# define FT_ERROR_PIPEX_EXEC_FAIL "minishell: command execution failed"
# define FT_ERROR_PIPEX_FD_DUP_FAIL "minishell: fd duplication failed"
# define FT_ERROR_PIPEX_PIPE_FAIL "minishell: pipe creation failed"
# define FT_ERROR_PIPEX_FORK_FAIL "minishell: fork creation failed"
# define FT_ERROR_PIPEX_OUTFILE_FAIL "minishell: error on opening output file"
# define FT_ERROR_PIPEX_INFILE_FAIL "minishell: error on opening input file"
# define FT_ERROR_PARSER_PIPE_LIMIT "minishell: pipe limit reached\n"
# define FT_ERROR_PARSER_ARG_OVERFLOW "minishell: argument overflow\n"
# define FT_ERR_PR_TK "minishell: syntax error near unexpected token'\n"
# define FT_ERR_PR_TK_PIPE "minishell: syntax error near unexpected token `|'\n"
# define FT_ERR_PR_TK_NL "minshell: syntax error near unexpected token `NL'\n"
# define FT_ERROR_EXIT_ARGS_NUM "minishell: exit: too many arguments\n"

# define CRED "\001\e[0;31m\002"
# define RESET "\001\e[0m\002"
# define FT_SHELL_NAME "minishe11-1.1$ "

typedef struct s_word
{
	char	*address;
	int		type;
}			t_word;

typedef struct s_command
{
	char	**comm_table ;
	int		comm_len;
	int		index;
	char	*path;
	int		cmd_type;
}			t_command;

typedef struct s_builtin_content
{
	char	*cmd;
	int		(*minishell_fct)(char **args, pid_t pid);
	int		index;
}				t_builtin_content;

typedef struct s_global
{
	int		signals;
	t_list	*env;
	t_list	*builtins;
	t_list	*parser2exec;
	t_list	*lexor2parser;
	char	*read_line2lexor;
	char	*last_return;
	char	*pwd;
	char	*home;
	char	*dp;
	int		inter;
}				t_global;

typedef struct s_env_var
{
	char	*name;
	char	*value;
}				t_env_var;

extern t_global	g_access;

/** INITIATOR */
/* ft_initiator_utils.c */

void	ft_update_shell_env(char *executable);
void	ft_init_builtins(void);
void	ft_envlist_cpy(char **envp);
void	ft_check_pwd_env(void);

/* ft_initiator.c */

void	ft_initiator(char **envp, char *executable);

/* ft_check_path_env_*.c */

void	ft_check_path_env(void);

/** MAIN/GLOBAL */
/* ft_check_symlink.c */

int		ft_check_symlink(char *path, char *arg, pid_t pid);

/* ft_free_linked_list.c */

void	del_env_var(void *tmp);
int		ft_free_linked_list(t_list **lst, int type, int full);

/* ft_globlal_fun.c */

void	free_global(void);

/* ft_rtoa_path.c */

void	ft_rtoa_path(char *rel_path, char **abs_path);

/* ft_signal_handler.c */

void	ft_signal_setup(void);

/* ft_utils.c */

int		ft_strcmp(char *s1, char *s2);
void	ft_set_global_pwd(char **env);
void	ft_smart_free(void **ptr);
void	ft_free_split(char **split);

/* ft_utils_join.c */

char	*ft_strjoin_with_free(char *s1, char const *s2);
char	*ft_strjoin_with_dfree(char *s1, char *s2);
char	*ft_strjoin_with_scnd_free(char *s1, char *s2);

/* ft_utils_num.c */

int		ft_digit_check(char *argv);
int		ft_atoll(const char *str, long long int *out);
char	*get_next_line(int fd);

#endif
