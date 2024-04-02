/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:35:01 by mamuller          #+#    #+#             */
/*   Updated: 2022/02/27 14:35:01 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_PRIVATE_H
# define FT_PARSER_PRIVATE_H

# include "../../../libft/incl/libft.h"

# define FT_CMD_TYPE_ERROR -1
# define FT_CMD_TYPE_SYSTEM 0
# define FT_CMD_TYPE_BUILT_IN 1
# define FT_CMD_TYPE_REDIRECT 2

# define PARSER_TABLE_LEN_LIMIT 1000
# define PIPE_LIMIT 1000

/** PARSER */
/* ft_parser.c */

void	ft_add_command(int cmd_len, char **cmd_line, int index_counter);

/* ft_parser_handler.c */

int		ft_parser_string_handler(t_list **lex_element, \
		char ***cmd_line, int *cmd_len, int index_counter);

/* ft_parser_utils.c */

char	**add_to_line(char **line, char *new_str, int *line_len);
int		ft_parser_error_handler(t_list **parser_list, t_list **lexor_list, \
		const char *msg);
int		is_redirect(char *str);
int		is_pipe(char *str);
int		ft_command_check(char *str, char **cmd_path, int *cmd_type);

/* ft_parser_path_finder.c */

int		path_finder(char *str, char **cmd_path);

#endif
