/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:23:01 by vali              #+#    #+#             */
/*   Updated: 2024/08/14 12:39:55 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_simple_str(char **str)
{
	free(*str);
	*str = NULL;
	return (0);
}

static void	gnl_read(int fd, char *buff, char **str)
{
	int	i;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0)
		{
			buff[i] = 0;
			if (!*str)
				*str = ft_substr(buff, 0, i);
			else
				*str = ft_strjoin(*str, buff, 1);
			if (ft_strchr(buff, '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
		if (i == -1)
			free_simple_str(str);
	}
	free(buff);
}

static char	*gnl_process_str(char **str)
{
	int		i;
	int		j;
	char	*temp;
	char	*result;

	if (!*str)
		return (0);
	if (**str == '\0')
		return (free_simple_str(str));
	if (!ft_strchr(*str, '\n'))
	{
		result = ft_substr(*str, 0, ft_strlen(*str));
		free_simple_str(str);
		return (result);
	}
	i = ft_strlen(*str);
	j = ft_strlen(ft_strchr(*str, '\n'));
	temp = *str;
	result = ft_substr(*str, 0, i - j + 1);
	*str = ft_substr(ft_strchr(*str, '\n'), 1, j - 1);
	free(temp);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buff;
	char		*line;

	if (BUFFER_SIZE < 1 || fd > 4096 || fd < 0)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
		return (free_simple_str(&str));
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	gnl_read(fd, buff, &str);
	line = gnl_process_str(&str);
	free_simple_str(&str);
	return (line);
}
/* 
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;

	fd = 10000;
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
