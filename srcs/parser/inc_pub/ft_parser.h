/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:35:01 by mamuller          #+#    #+#             */
/*   Updated: 2022/02/27 14:35:01 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "../../../libft/incl/libft.h"

# define FT_CMD_TYPE_ERROR -1
# define FT_CMD_TYPE_SYSTEM 0
# define FT_CMD_TYPE_BUILT_IN 1
# define FT_CMD_TYPE_REDIRECT 2

# define FT_LIST_TYPE_WORD 0
# define FT_LIST_TYPE_COMMAND 1
# define FT_LIST_TYPE_BUILTIN_CONTENT 2
# define FT_LIST_TYPE_ENV_VAR 3

# define PARSER_TABLE_LEN_LIMIT 1000
# define PIPE_LIMIT 1000

typedef struct s_command
{
	char	**comm_table ;
	int		comm_len;
	int		index;
	char	*path;
	int		cmd_type;
}			t_command;

/** PARSER */
/* ft_parser.c */

int		ft_parser(void);

#endif
