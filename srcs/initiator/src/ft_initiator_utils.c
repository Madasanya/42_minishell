/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:51:45 by dbanfi            #+#    #+#             */
/*   Updated: 2022/02/21 13:51:45 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../../libft/incl/libft.h"
#include "../../builtin/inc_pub/ft_builtin.h"
#include "../../utils/inc_pub/ft_utils.h"

/**
	 @brief Handling SHELL in copied list. Updated to path to exe of minishell.
	 @param executable String with name of minishell executable.
	 @return None.
*/
void	ft_update_shell_env(char *executable)
{
	t_list		*ptr;
	t_env_var	*env_var;

	ptr = g_access.env;
	while (ptr)
	{
		if (!ft_strncmp(((t_env_var *)(ptr->content))->name, "SHELL=", 6))
		{
			ft_smart_free((void **)&(((t_env_var *)(ptr->content))->value));
			ft_rtoa_path(executable, &(((t_env_var *)(ptr->content))->value));
			return ;
		}
		ptr = ptr->next;
	}
	env_var = (t_env_var *)malloc(sizeof(t_env_var));
	env_var->name = ft_strdup("SHELL=");
	ft_rtoa_path(executable, &(env_var->value));
	ft_lstadd_back(&(g_access.env), ft_lstnew(env_var));
}

/**
	 @brief Creating a copy of the original env list.
	 @param envp Original environmental variables list.
	 @return None.
	 @exception As per start of a shell OLPWD is not existent.
 */
void	ft_envlist_cpy(char **envp)
{
	int			i;
	int			j;
	t_env_var	*env_var;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "OLDPWD", 6))
		{
			j = 0;
			while (envp[i][j] != '=' && envp[i][j] != '\0')
				j++;
			if (!ft_strncmp(envp[i], "PWD", 3))
				g_access.pwd = ft_strdup(&(envp[i][j + 1]));
			if (envp[i][j] == '=')
			{
				env_var = (t_env_var *)malloc(sizeof(t_env_var));
				env_var->name = ft_substr(envp[i], 0, j + 1);
				env_var->value = ft_strdup(&(envp[i][j + 1]));
				ft_lstadd_back(&(g_access.env), ft_lstnew(env_var));
			}
		}
		i++;
	}
}

/**
	 @brief Handling unexistent PWD in copied list.
	 @return None.
	 @exception As per start of a shell PWD is always existent,
	 			even if unset in parent shell
 */
void	ft_check_pwd_env(void)
{
	t_env_var	*env_var;

	if (g_access.pwd == NULL)
		ft_set_global_pwd(&g_access.pwd);
	if (env_value_finder("PWD") == NULL)
	{
		env_var = (t_env_var *)malloc(sizeof(t_env_var));
		env_var->name = ft_substr("PWD=", 0, 4);
		env_var->value = ft_strdup(g_access.pwd);
		ft_lstadd_back(&(g_access.env), ft_lstnew(env_var));
	}
	else if (ft_strlen(env_value_finder("PWD")) == 0)
		ft_update_env("PWD", g_access.pwd);
	if (ft_check_symlink(env_value_finder("PWD"), NULL, 0) \
		|| ft_check_symlink((g_access.pwd), NULL, 0))
	{
		g_access.dp = ft_strdup(env_value_finder("PWD"));
	}
}
