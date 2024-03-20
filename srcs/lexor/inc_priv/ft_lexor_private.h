/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexor_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggi <maggi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:35:01 by mamuller          #+#    #+#             */
/*   Updated: 2024/03/20 21:41:58 by maggi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXOR_PRIVATE_H
# define FT_LEXOR_PRIVATE_H

# include "../../../libft/incl/libft.h"
// # include <stdio.h>
// # include <readline/readline.h>
// # include <readline/history.h>
// # include <unistd.h>
// # include <stdlib.h>
// # include <errno.h>
// # include <string.h>
// # include <sys/wait.h>
// # include <stdarg.h>
// # include <fcntl.h>
// # include <sys/types.h>
// # include <signal.h>
// # include <dirent.h>
// # include <sys/stat.h>

# define FT_SPECIAL_CHAR_STRING 1
# define FT_STRING 2

# define FT_TAB 9
# define FT_SPACE 32
# define FT_SINGLE_QUOTE 39
# define FT_DOUBLE_QUOTE 34
# define FT_DOLLAR_SIGN 36
# define FT_HASHTAG	35
# define FT_GREATER 62
# define FT_LESSER 60
# define FT_QUESTION_MARK 63
# define FT_MINUS 45
# define FT_EQUAL 61
# define FT_PIPE 124
# define FT_WILDCARD 42
# define FT_L_PAR 40
# define FT_R_PAR 41
# define FT_AMPERSAND 38
# define FT_TILDE 126
# define FT_EXCL_MARK 33
# define FT_UNDERSCORE 95

/* ft_lexor_handlers.c */

void	ft_lex_space_handler(char **current_str, char *args, \
		int begining, int i);
void	ft_lex_operand_handler(char **current_str, char *args, \
		int begining, int i);
int		ft_lex_single_quote_handler(char **current_str, char *args, \
		int begining, int i);
int		ft_lex_double_quote_handler(char **current_str, char *args, \
		int begining, int i);
void	ft_lex_string_reminder_handler(char **current_str, char *args, \
		int begining, int i);

/* ft_lexor_utils.c */

char	*join2current_str(char *current_str, char *add_on);
void	add_string(t_list **list, char	*str);
int		is_space(char ch);
int		is_special_char(char ch);

/* ft_lexor_utils2.c */

void	add_specialchar_string(t_list **list, char *str);
int		q_handler(char *str, char **current_str, char q_char);
void	ft_comment_check(char **args);

/* ft_lexor_env_check.c */

void	ft_env_check(char **args);

#endif /* FT_LEXOR_PRIVATE_H */
