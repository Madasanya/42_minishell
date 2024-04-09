/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:35:01 by mamuller          #+#    #+#             */
/*   Updated: 2022/02/27 14:35:01 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PRIVATE_H
# define PIPEX_PRIVATE_H

# include "../../../libft/incl/libft.h"
# include <sys/types.h>


# define OUT_WRITE 0
# define OUT_APPEND 1
# define IN_READFILE 2
# define IN_HEREDOC 3

typedef struct s_fd
{
	int	in[2];
	int	out[2];
}	t_fd;

/** EXECUTOR/PIPEX */
/* ft_executor.c */

void	ft_executor(char **envp);

/* ft_pipex.c */

void	ft_pipex(int fd_s[2], char **envp, int **fd_d, pid_t *pidt);

/* ft_pipex_error_handling.c */

void	ft_err_ch(char *error_msg, int **fd_docks, int fd_stream[2], \
		pid_t *pidt);
void	ft_err_par(char *error_msg, int **fd_docks, int fd_stream[2], \
		pid_t *pidt);
void	ft_ch_err_fl(int error_flag, int **fd_docks, \
		int *fd_stream, pid_t *pidt);
int		ft_fc_error_exit(int error_flag, t_fd fd);
void	ft_pipex_child_in_out_error(int error_flag, t_fd fd);

/* ft_pipex_filecheck.c */

int		ft_fc(t_list **cmd_list, int i, t_fd fd, int *fd_docks);

/* ft_pipex_utils.c */

void	ft_pipex_iterator(int *i, t_list **cmd_list);
void	ft_pipex_clean_child_exec(t_list *cmd_list, \
		char **envp, pid_t *pidt, int i);
void	ft_pipex_parent_exec(t_list **cmd_list, t_fd fd, int i, int *pidt);
int		ft_execve(char **args, pid_t pid);

#endif
