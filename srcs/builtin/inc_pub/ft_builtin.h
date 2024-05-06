/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:35:01 by mamuller          #+#    #+#             */
/*   Updated: 2024/05/06 20:12:07 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

# include "../../../libft/incl/libft.h"

/* ft_builtin_cd.c */

int		minishell_cd(char **args, pid_t pid);

/* ft_builtin_echo.c */

int		minishell_echo(char **args, pid_t pid);

/* ft_builtin_env_utils.c */

char	*env_value_finder(char *name);
void	ft_update_env(char *to_search, char *to_replace);

/* ft_builtin_env.c */

int		minishell_env(char **args, pid_t pid);

/* ft_builtin_exit.c */

int		minishell_exit(char **args, pid_t pid);

/* ft_builtin_export.c */

int		minishell_export(char **args, pid_t pid);

/* ft_builtin_init.c */

void	ft_builtin_init(void);

/* ft_builtin_pwd.c */

int		minishell_pwd(char **args, pid_t pid);

/* ft_builtin_unset.c */

int		minishell_unset(char **args, pid_t pid);

#endif /* FT_BUILTIN_H */
