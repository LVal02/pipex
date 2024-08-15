/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:54:23 by se                #+#    #+#             */
/*   Updated: 2024/08/14 12:40:33 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_and_f_if_exist(char *to_print, t_data *data, char *str1,
		char *str2)
{
	ft_putstr_fd(to_print, 1);
	if (data)
		ft_free((void **)&data);
	if (str1)
		ft_free((void **)&str1);
	if (str2)
		ft_free((void **)&str2);
	exit(1);
}

void	check_splits_free(char *to_print, char **path, t_data *data,
		int freedata)
{
	if (to_print)
	{
		ft_putstr_fd(to_print, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	if (path)
		ft_free_split((void ***)&path);
	if (data)
	{
		if (data->env_paths)
			ft_free_split((void ***)&(data->env_paths));
		if (data->command)
			ft_free_split((void ***)&(data->command));
		if (data->command_path)
			ft_free((void **)&data->command_path);
		if (data->pid)
			ft_free((void **)&data->pid);
		ft_close_fd(&data->prev_pipe);
		ft_close_fd(&data->fd[0]);
		ft_close_fd(&data->fd[1]);
		if (freedata)
			ft_free((void **)&data);
	}
	exit(0);
}
