/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:24:49 by se                #+#    #+#             */
/*   Updated: 2024/08/14 12:42:03 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_command(t_data *data, char *command, int j)
{
	data->command = ft_split(command, ' ');
	if (!data->command)
		check_splits_free(MALLOC_FAILED, NULL, data, 0);
	data->command_path = assign_path_command(data->command[0], data);
	redirect(data, j);
	if (execve(data->command_path, data->command, data->envp) == -1)
	{
		if (ft_strcmp(data->command_path, data->command[0]) == 0)
		{
			ft_putstr_fd(data->command_path, STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			check_splits_free(data->command_path, NULL, data, 0);
		}
		check_splits_free(EXECVE_FAILED, NULL, data, 1);
	}
}

static void	wait_proccesses(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->nb_command)
	{
		waitpid(data->pid[i], &status, 0);
		if (WEXITSTATUS(status) != EXIT_SUCCESS)
			check_splits_free(NULL, NULL, data, 0);
		i++;
	}
}

void	process_fork(t_data *data, char **argv, int i)
{
	int	j;

	j = 0;
	while (j < data->nb_command)
	{
		if (j != data->nb_command - 1 && pipe(data->fd) == -1)
			check_splits_free(PIPE_FAILED, NULL, data, 0);
		data->pid[j] = fork();
		if (data->pid[j] == -1)
			check_splits_free(FORK_FAILED, NULL, data, 0);
		if (data->pid[j] == 0)
			process_command(data, argv[j + i], j);
		else
		{
			data->fd[1] = ft_close_fd(&data->fd[1]);
			if (data->prev_pipe != -1)
				ft_close_fd(&data->prev_pipe);
			data->prev_pipe = data->fd[0];
			data->fd[0] = -1;
			j++;
		}
	}
	wait_proccesses(data);
}
