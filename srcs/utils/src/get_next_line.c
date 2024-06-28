/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:40:49 by dbanfi            #+#    #+#             */
/*   Updated: 2022/02/26 16:40:49 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static char	*ft_strjoin_gnl(char *s1, char *s2, int j)
{
	char	*return_s;
	int		len_s1;
	int		len_s2[2];
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2[0] = ft_strlen(s2);
	len_s2[1] = len_s2[0] - (ft_strchr(s2, '\0') - ft_strchr(s2, '\n'));
	return_s = malloc(sizeof(char) * (len_s1 + len_s2[j] + 1) + 1);
	if (return_s == NULL)
		return (NULL);
	while (i < len_s1 + len_s2[j] + 1)
	{
		if (i < len_s1)
			return_s[i] = s1[i];
		else
			return_s[i] = s2[i - len_s1];
		i++;
	}
	return_s[(len_s1 + len_s2[j] + 1)] = '\0';
	free(s1);
	return (return_s);
}

static void	ft_memmove_till_newline(char *l_to_m)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (l_to_m[i] != '\0')
	{
		if (l_to_m[i] == '\n')
		{
			len = ft_strchr(l_to_m + i + 1, '\0') - (l_to_m + i);
			ft_memmove(l_to_m, (l_to_m) + i + 1, len);
			break ;
		}
		i++;
	}
	ft_bzero((l_to_m) + len, i + 1);
}

static int	ft_return_prep(int bytes, char **tmp, char **line, int fd)
{
	if (bytes > 0)
		return (1);
	else if (bytes == 0)
		return (0);
	else
	{
		if (fd >= 0 && fd <= 1024)
			free(*line);
		*line = NULL;
		*tmp = NULL;
		return (-1);
	}
}

static int	ft_check_array_input(char **tmp, char **line, char *buffer, int fd)
{
	int	bytes;

	bytes = 1;
	if (*line)
	{
		ft_bzero(*line, ft_strlen(*line));
		*tmp = *line;
	}
	else
	{
		*tmp = malloc(1);
		*tmp[0] = '\0';
	}
	if (!*buffer)
		bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		*tmp = ft_strjoin_gnl(*tmp, buffer, 0);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (-1);
	}
	return (bytes);
}

static int	get_next_line_prev(int fd, char **line)
{
	int			bytes;
	static char	buffer[BUFFER_SIZE + 1];
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || fd > 1024 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (ft_return_prep(-1, &tmp, line, fd));
	bytes = ft_check_array_input(&tmp, line, (char *)&buffer[0], fd);
	if (bytes > 0 && ft_strchr((char *)&buffer[0], '\n'))
	{
		tmp = ft_strjoin_gnl(tmp, (char *)&buffer[0], 1);
		ft_memmove_till_newline((char *)&buffer[0]);
	}
	else if (bytes > 0)
		tmp = ft_strjoin_gnl(tmp, (char *)&buffer[0], 0);
	*line = tmp;
	return (ft_return_prep(bytes, &tmp, line, fd));
}

char	*get_next_line(int fd)
{
	char	*line;
	int		bytes;

	line = NULL;
	bytes = get_next_line_prev(fd, &line);
	if ((bytes == -1) || (bytes == 0 && ft_strlen(line) == 0))
	{
		free(line);
		return (NULL);
	}
	else
		return (line);
}
