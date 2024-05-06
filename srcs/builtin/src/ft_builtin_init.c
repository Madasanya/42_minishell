/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:07:49 by mamuller          #+#    #+#             */
/*   Updated: 2024/05/06 20:10:48 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"
#include "../inc_priv/ft_builtin_private.h"

/**
	@brief Adds a buildin to linked list.
	@return Pointer to content element that can be added to buildin list.
*/
static t_builtin_content	*ft_builtin_content_init(char *cmd, \
	int (*minishell_fct)(char **args, pid_t pid), int i)
{
	t_builtin_content	*content;

	content = ft_calloc(sizeof(t_builtin_content), 1);
	content->cmd = cmd;
	content->minishell_fct = minishell_fct;
	content->index = i;
	return (content);
}

/**
	@brief Builds linked list with all builtins.
	@return None.
*/
void	ft_builtin_init(void)
{
	ft_lstadd_back(&(g_access.builtins), \
		ft_lstnew(ft_builtin_content_init("echo", minishell_echo, 0)));
	ft_lstadd_back(&(g_access.builtins), \
		ft_lstnew(ft_builtin_content_init("cd", minishell_cd, 1)));
	ft_lstadd_back(&(g_access.builtins), \
		ft_lstnew(ft_builtin_content_init("pwd", minishell_pwd, 2)));
	ft_lstadd_back(&(g_access.builtins), \
		ft_lstnew(ft_builtin_content_init("export", minishell_export, 3)));
	ft_lstadd_back(&(g_access.builtins), \
		ft_lstnew(ft_builtin_content_init("unset", minishell_unset, 4)));
	ft_lstadd_back(&(g_access.builtins), \
		ft_lstnew(ft_builtin_content_init("env", minishell_env, 5)));
	ft_lstadd_back(&(g_access.builtins), \
		ft_lstnew(ft_builtin_content_init("exit", minishell_exit, 6)));
}