/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiator_private.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:35:01 by mamuller          #+#    #+#             */
/*   Updated: 2022/02/27 14:35:01 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INITIATOR_PRIVATE_H
# define FT_INITIATOR_PRIVATE_H

/** INITIATOR */
/* ft_initiator_utils.c */

void	ft_update_shell_env(char *executable);
void	ft_envlist_cpy(char **envp);
void	ft_check_pwd_env(void);

#endif
