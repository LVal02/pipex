/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:11:28 by se                #+#    #+#             */
/*   Updated: 2024/08/14 12:38:37 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*assign_path_command(char *command, t_data *data)
{
	char	*path;
	int		i;

	if (access(command, F_OK) == 0)
	{
		path = ft_strdup(command);
		if (!path)
			check_splits_free(MALLOC_FAILED, NULL, data, 0);
		return (path);
	}
	i = 0;
	while (data->env_paths && data->env_paths[i])
	{
		path = ft_strjoin(data->env_paths[i], command, 0);
		if (!path)
			check_splits_free(MALLOC_FAILED, NULL, data, 0);
		if (access(path, F_OK) == 0)
			return (path);
		ft_free((void **)&path);
		i++;
	}
	path = ft_strdup(command);
	if (!path)
		check_splits_free(MALLOC_FAILED, NULL, data, 0);
	return (path);
}

char	**search_path(t_data *data)
{
	char	**paths;
	int		i;

	if (data->envp == NULL)
		return (NULL);
	i = 0;
	while (data->envp[i] && !ft_strnstr(data->envp[i], "PATH", 4))
		i++;
	if (data->envp[i] == NULL)
		return (NULL);
	paths = ft_split(data->envp[i] + 5, ':');
	if (!paths)
		check_and_f_if_exist(MALLOC_FAILED, data, NULL, NULL);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/", 1);
		if (!paths[i])
			check_splits_free(MALLOC_FAILED, paths, data, 0);
		i++;
	}
	return (paths);
}
