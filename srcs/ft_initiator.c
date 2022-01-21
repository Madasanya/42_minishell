#include "../incl/minishe11.h"
#include "../incl/minishell.h"

/** !!!!!!!!!! Remove as soon as replacement with Lexer/Parser return value possible !!!!!!!!!!! **/
char	**minishell_split_line(char *line)
{
	int		buffer;
	int		bufsize;
	int		position;
	char	**tokens;
	char	*token;

	buffer = 64;
	bufsize = buffer;
	position = 0;
	tokens = malloc(bufsize * sizeof(char*));
	if (!tokens)
	{
		write(2, "minishell: allocation error\n", 28);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += buffer;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				write(2, "minishell: allocation error\n", 28);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}


/*Functions to keep*/

t_builtin_content *ft_init_builtin_content(char *cmd, int (*minishell_fct)(char **args, t_shell *shell), int i)
{
	t_builtin_content	*content;

	content = calloc(sizeof(t_builtin_content), 1);
	content->cmd = cmd;
	content->minishell_fct = minishell_fct;
	content->index = i;
	return(content);
}

void ft_init_builtins(void)
{
	ft_lstadd_back(g_access.builtins, ft_lstnew(ft_init_builtin_content("echo", minishell_echo, 0)));
	ft_lstadd_back(g_access.builtins, ft_lstnew(ft_init_builtin_content("cd", minishell_cd, 1)));
	ft_lstadd_back(g_access.builtins, ft_lstnew(ft_init_builtin_content("pwd", minishell_pwd, 2)));
	ft_lstadd_back(g_access.builtins, ft_lstnew(ft_init_builtin_content("export", minishell_export, 3)));
	ft_lstadd_back(g_access.builtins, ft_lstnew(ft_init_builtin_content("unset", minishell_unset, 4)));
	ft_lstadd_back(g_access.builtins, ft_lstnew(ft_init_builtin_content("env", minishell_env, 5)));
	ft_lstadd_back(g_access.builtins, ft_lstnew(ft_init_builtin_content("exit", minishell_exit, 6)));
}

/*
	WHEN CREATING ENV LIST, WE MUST ALSO ADD THE _= VARIABLE \
	EVEN WHEN WE MANIPULATE IT IN OUR BUILTINS;
	AT THIS MOMENT, THE _= DOES NOT EXIST;
	COMMENTED LINES INSIDE THE FUNCTION ARE FOR TESTING PURPOSES;
*/

void ft_create_envlist(char **envp)
{
	int i, j;
	t_env_var *env_var;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j] != '\0')
			j++;
		if (envp[i][j] == '=')
		{
			env_var = (t_env_var *)malloc(sizeof(t_env_var));
			env_var->name = ft_substr(envp[i], 0, j + 1);
			env_var->value = ft_strdup(&(envp[i][j + 1]));
			ft_lstadd_back(g_access.env, ft_lstnew(env_var));
		}
		i++;
	}
}

void ft_initiator_exc(char **envp)
{
	ft_create_envlist(envp);
	ft_init_builtins();
}