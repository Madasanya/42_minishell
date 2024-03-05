/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:35:01 by mamuller          #+#    #+#             */
/*   Updated: 2024/03/05 21:35:01 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_PRIVATE_H
# define FT_BUILTIN_PRIVATE_H

# define FT_UNSET_MSG_TYPE 0
# define FT_EXPORT_MSG_TYPE 1

/* ft_builtin_env_utils.c */

char	*env_value_finder(char *name);
void	ft_update_env(char *to_search, char *to_replace);
void	ft_update_create_env(char *env, char *value, pid_t pid);
int		ft_env_name_check(char *args_word, int *valid, pid_t pid, int mes_type);

/* ft_builtin_exit_utils.c */

void	ft_child_exit(int exit_value);
void	ft_exit_error_handler(char *str1, char *str2, char *str3, \
		int exit_value);

/* ft_builtin_export_utils.c */

t_list	*ft_copy_env(void);
void	ft_print_sorted_copy(t_list *env_cpy);

/* ft_builtin_utils.c */

void	ft_last_arg(char **args, pid_t pid);
void	ft_set_lasts(char **args, int pid, int lreturn, int mode);
void	ft_path_cleaner(char **cp);

#endif
