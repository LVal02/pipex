/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:17:11 by se                #+#    #+#             */
/*   Updated: 2024/08/14 12:38:30 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2(int *fd, int fd_to_replace, t_data *data, char *fd_name)
{
	if (dup2(*fd, fd_to_replace) == -1)
	{
		ft_close_fd(fd);
		check_splits_free(fd_name, NULL, data, 1);
	}
	ft_close_fd(fd);
}

void	file_to_stdin(char *file_to_stdin, t_data *data)
{
	int	fd;

	ft_close_fd(&data->fd[0]);
	fd = open(file_to_stdin, O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_putstr_fd(file_to_stdin, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		fd = open("/dev/null", O_RDONLY);
		if (fd == -1)
			check_splits_free("Error opening /dev/null", NULL, data, 1);
	}
	ft_dup2(&fd, STDIN_FILENO, data, file_to_stdin);
}

void	file_to_stdout(char *file_to_stdout, t_data *data)
{
	int	fd;

	ft_close_fd(&data->fd[0]);
	ft_close_fd(&data->fd[1]);
	if (data->limiter == NULL)
	{
		fd = open(file_to_stdout, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
	{
		fd = open(file_to_stdout, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	if (fd == -1)
		check_splits_free(file_to_stdout, NULL, data, 1);
	ft_dup2(&fd, STDOUT_FILENO, data, file_to_stdout);
}

void	redirect(t_data *data, int j)
{
	if (j == 0)
	{
		file_to_stdin(data->input_file, data);
		ft_dup2(&data->fd[1], STDOUT_FILENO, data, "pipe[1]");
	}
	else if (j == data->nb_command - 1)
		file_to_stdout(data->output_file, data);
	else
	{
		ft_close_fd(&data->fd[0]);
		ft_dup2(&data->fd[1], STDOUT_FILENO, data, "pipe[1]");
	}
	if (data->prev_pipe != -1)
		ft_dup2(&data->prev_pipe, STDIN_FILENO, data, "previous pipe");
}
