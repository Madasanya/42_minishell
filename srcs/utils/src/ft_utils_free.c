/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:32:17 by dbanfi            #+#    #+#             */
/*   Updated: 2024/07/25 00:26:54 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"
#include "../../parser/inc_pub/ft_parser.h"
#include "../inc_pub/ft_utils.h"

/**
	@brief Del function for ft_lstclear() in case of content structure
		being t_word. Used in s_global element lexor2parser.
	@param tmp Void pointer to content of linked list node.
	@return None.
*/
static void	del_word(void *tmp)
{
	if (((t_word *)(tmp))->address != NULL)
		free(((t_word *)(tmp))->address);
	if (tmp != NULL)
		free(tmp);
	tmp = NULL;
}

/**
	@brief Del function for ft_lstclear() in case of content structure
		being t_command. Used in s_global element parser2exec.
	@param tmp Void pointer to content of linked list node.
	@return None.
*/
static void	del_command(void *tmp)
{
	if (((t_command *)(tmp))->comm_table != NULL)
		ft_free_split(((t_command *)(tmp))->comm_table);
	if (((t_command *)(tmp))->path != NULL)
		free(((t_command *)(tmp))->path);
	if (tmp != NULL)
		free(tmp);
	tmp = NULL;
}

/**
	@brief Del function for ft_lstclear() in case of content structure
		being t_builtin_content. Used in s_global element parser2exec.
	@param tmp Void pointer to content of linked list node.
	@return None.
*/
static void	del_builtin_content(void *tmp)
{
	if (tmp != NULL)
		free(tmp);
	tmp = NULL;
}

/**
	@brief Del function for ft_lstclear() in case of content structure
		being t_env_var. Used in s_global element env.
	@param tmp Void pointer to content of linked list node.
	@return None.
*/
void	del_env_var(void *tmp)
{
	if (((t_env_var *)(tmp))->name != NULL)
		free(((t_env_var *)(tmp))->name);
	if (((t_env_var *)(tmp))->value != NULL)
		free(((t_env_var *)(tmp))->value);
	if (tmp != NULL)
		free(tmp);
	tmp = NULL;
}

/**
	@brief Frees linked list according to type. Has an option to free
		linked list pointer as well.
	@param lst Pointer to liked list to be freed.
	@param type Type of linked list passed in parameter lst.
	@param full Option to free linked list pointer as well.
	@return Returns -2 if it gets passed NULL pointer in lst, -1 if type
		is unknown, 0 on success.
*/
int	ft_free_linked_list(t_list **lst, int type, int full)
{
	if (lst == NULL)
		return (-2);
	if (type == FT_LIST_TYPE_WORD)
		ft_lstclear(lst, del_word);
	else if (type == FT_LIST_TYPE_COMMAND)
		ft_lstclear(lst, del_command);
	else if (type == FT_LIST_TYPE_BUILTIN_CONTENT)
		ft_lstclear(lst, del_builtin_content);
	else if (type == FT_LIST_TYPE_ENV_VAR)
		ft_lstclear(lst, del_env_var);
	else
		return (-1);
	if (full)
	{
		free(*lst);
		*lst = NULL;
	}
	return (0);
}

/**
	@brief Frees globly used variables. Frees global structute g_access
		and readline history.
	@return None.
	@exception Insert "rl_clear_history();" on line 38 to free readline
		history works only with linux readline libraries.
*/
void	free_global(void)
{
	if (g_access.env)
		ft_free_linked_list(&(g_access.env), FT_LIST_TYPE_ENV_VAR, 1);
	if (g_access.builtins)
		ft_free_linked_list(&(g_access.builtins), \
			FT_LIST_TYPE_BUILTIN_CONTENT, 1);
	ft_smart_free((void **)&g_access.last_return);
	if (g_access.lexor2parser)
		ft_free_linked_list(&(g_access.lexor2parser), FT_LIST_TYPE_WORD, 1);
	if (g_access.parser2exec)
		ft_free_linked_list(&(g_access.parser2exec), FT_LIST_TYPE_COMMAND, 1);
	ft_smart_free((void **)&g_access.read_line2lexor);
	ft_smart_free((void **)&g_access.home);
	ft_smart_free((void **)&g_access.pwd);
	ft_smart_free((void **)&g_access.dp);
}
