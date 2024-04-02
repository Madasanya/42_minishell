/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggi <maggi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:35:01 by mamuller          #+#    #+#             */
/*   Updated: 2024/04/01 22:04:56 by maggi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXOR_H
# define FT_LEXOR_H

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

/* ft_lexor.c */

int		ft_lexor(void);

#endif /* FT_LEXOR_H */
