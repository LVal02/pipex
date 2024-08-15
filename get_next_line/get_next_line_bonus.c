/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: se <se@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:23:01 by vali              #+#    #+#             */
/*   Updated: 2024/08/05 04:21:04 by se               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_simple_str(char **str, int fd)
{
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}

static void	gnl_read(int fd, char *buff, char **str)
{
	int		i;
	char	*temp;

	if (!str[fd] || !ft_strchr(str[fd], '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0)
		{
			buff[i] = 0;
			if (!str[fd])
				str[fd] = ft_substr(buff, 0, i);
			else
			{
				temp = str[fd];
				str[fd] = ft_strjoin(str[fd], buff);
				free(temp);
			}
			if (ft_strchr(buff, '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
		if (i == -1)
			free_simple_str(str, fd);
	}
	free(buff);
}

static char	*gnl_process_str(char *str[], int fd)
{
	int		i;
	int		j;
	char	*temp;
	char	*result;

	if (!str[fd])
		return (0);
	if (*str[fd] == '\0')
		return (free_simple_str(str, fd));
	if (!ft_strchr(str[fd], '\n'))
	{
		result = ft_substr(str[fd], 0, ft_strlen(str[fd]));
		free_simple_str(str, fd);
		return (result);
	}
	i = ft_strlen(str[fd]);
	j = ft_strlen(ft_strchr(str[fd], '\n'));
	result = ft_substr(str[fd], 0, i - j + 1);
	temp = str[fd];
	str[fd] = ft_substr(ft_strchr(str[fd], '\n'), 1, j - 1);
	free(temp);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*buff;
	char		*line;

	if (BUFFER_SIZE < 1 || fd > 4096 || fd < 0)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
		return (free_simple_str(str, fd));
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	gnl_read(fd, buff, str);
	line = gnl_process_str(str, fd);
	if (line == NULL && str[fd] == NULL)
		free_simple_str(str, fd);
	return (line);
}
/*
 #include <fcntl.h>
 #include <stdio.h>
 #include "get_next_line.h"
 int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

*/
