#include "../incl/minishell.h"

/**
	 @brief Bultin command: change directory.
	 @param args List of args. args[0] is "cd". args[1] is the directory.
	 @return Always returns 1, to continue executing.
	 @todo CHECK IF PWD EXISTS AND CREATE IT IF IT DOESN'T, AFTER USING CD; (idea: change PWD to PWD1 if using 'unset' on PWD)
 */
int	minishell_cd(char **args, ...)
{
	char *temp[2];
	int len;
	va_list arg;
	
	va_start(arg, *args);
	len = va_arg(arg, int);
	va_end(arg);
	temp[1] = ft_strjoin("OLDPWD=", g_access.pwd);
	t_list *ptr = g_access.env;
	args[1] = ft_handle_cd(args[1], ptr);
//see if implementation of error_printing can be made inside ft_handle_cd
	if (args[1] == NULL)
	{
		write(1, "minishell: cd: HOME not set\n", 28);
		ft_update_env("_=", "cd");
		return (1);
	}
	else if (!ft_strncmp(args[1], ";", 1))
	{
		write(1, "minishell: cd: OLDPWD not set\n", 30);
		ft_update_env("_=", "cd");
		return (1);
	}
	ft_update_create_OLDPWD(temp, ptr, len);
	if ((chdir(args[1]) != 0))
		perror(ft_strjoin("minishell: cd: ", args[1]));
	ft_update_PWD(args[1]);
	free(temp[1]);
	ft_update_env("_=", "cd");
	return (1);
}



/**
	 @brief Builtin command: echo.
	 @param args List of args.	Not examined.
	 @return Always returns 1, to continue execution.
	 @todo edge case fetch -nnnnn -nnnn test / edge case echo $_ -> $_ must be implemented alongside history; implemented -nnnnnnnn and also implemented -nnnnn -nnnn V.
 */
int	minishell_echo(char **args, ...)
{
	int i;
	int flag;
	int temp;
	int len;
	va_list arg;
	
	va_start(arg, *args);
	len = va_arg(arg, int);
	va_end(arg);
	flag = 0;
	if (args[1] == NULL)
		write(2, "minishell: expected argument to \"echo\"\n", 40);
	else
	{
		i = 1;
		while (args[i]) //go through all arguments
		{
			temp = echo_flag(args[i]); //checks for -n / -nnnnnnn and returns 1 if so or 0 if the format is not -n / -nnnnn
			flag += temp; //flag keeps growing by temp
			if (flag == 0 || temp == 0)
				break;
			else
				i++;
		}
		echo_print(args, i, len, flag); //based on the flag, we either print with or without a \n
	}
	ft_update_env("_=", "echo");
	return (1);
}
