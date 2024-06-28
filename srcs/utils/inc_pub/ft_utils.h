/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 00:10:33 by mamuller          #+#    #+#             */
/*   Updated: 2024/06/29 01:08:07 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "../../../libft/incl/libft.h"

/* ft_check_path_env_*.c */

void	ft_check_path_env(void);

/* ft_check_symlink.c */

int	ft_check_symlink(char *path, char *arg, pid_t pid);

/* ft_rtoa_path.c */

void	ft_rtoa_path(char *rel_path, char **abs_path);

/* ft_utils_free.c */

void	del_env_var(void *tmp);
int	    ft_free_linked_list(t_list **lst, int type, int full);

/* ft_utils_join.c */

char	*ft_strjoin_with_free(char *s1, char const *s2);
char	*ft_strjoin_with_dfree(char *s1, char *s2);
char	*ft_strjoin_with_scnd_free(char *s1, char *s2);

/* ft_utils_num.c */

int	ft_digit_check(char *argv);
int	ft_atoll(const char *str, long long int *out);

/* ft_utils.c */

int	ft_strcmp(char *s1, char *s2);

/* get_next_line.c */

char	*get_next_line(int fd);

#endif /* FT_BUILTIN_H */
