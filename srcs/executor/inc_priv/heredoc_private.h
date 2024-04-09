/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:35:01 by mamuller          #+#    #+#             */
/*   Updated: 2022/02/27 14:35:01 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_PRIVATE_H
# define HEREDOC_PRIVATE_H

# include "../../../libft/incl/libft.h"
# include <sys/types.h>

/** EXECUTOR/PIPEX */

/* ft_heredoc.c */

void	ft_heredoc_pipe_init(int **fd_docks, int fd_stream[2], int index);
void	ft_heredoc_parent(int *fd, pid_t pid);
void	ft_heredoc(char *stop_word, int fd_stream[2], int fd_out, \
		char *keyword);
void	ft_hd_ch(int *fd, int *fd_stream, char *stop_word, char *keyword);

/* ft_heredoc_utils.c */

void	ft_heredoc_child_free(int **fd_docks);
void	ft_handle_sigterm_heredoc(int signum);
void	ft_free_heredoc_fds(int **fd_docks);

#endif
