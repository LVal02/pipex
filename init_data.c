/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:31:55 by vali              #+#    #+#             */
/*   Updated: 2024/08/14 12:38:41 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_limiter(char *input, t_data *data)
{
	size_t	len;
	char	*end;

	len = ft_strlen(input);
	if (len <= 1)
		return (0);
	end = &input[len - 1];
	if (*end == '\n')
		*end = '\0';
	if (ft_strcmp(input, data->limiter) == 0)
		return (1);
	else
		*end = '\n';
	return (0);
}

void	redirect_fd_file(char **inp_joined, t_data *data)
{
	int	fd;

	fd = open(HERE_DOC_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_free((void **)inp_joined);
		check_and_f_if_exist("fail open", data, NULL, NULL);
	}
	if (ft_putstr_fd(*inp_joined, fd) == -1)
	{
		fd = ft_close_fd(&fd);
		ft_free((void **)inp_joined);
		check_and_f_if_exist("fail to put infile", data, NULL, NULL);
	}
	fd = ft_close_fd(&fd);
	ft_free((void **)inp_joined);
	*inp_joined = NULL;
}

char	*process_input(t_data *data)
{
	char	*input;
	char	*input_joined;

	input_joined = ft_strdup("");
	if (!input_joined)
		check_and_f_if_exist("failed ft_strdup in P_input", data, NULL, NULL);
	while (1)
	{
		if (write(1, "pipe heredoc> ", 14) == -1)
			check_and_f_if_exist("f write process_input", data, NULL, NULL);
		input = get_next_line(STDIN_FILENO);
		if (!input)
			check_and_f_if_exist("gnl failed", data, input, input_joined);
		if (check_limiter(input, data) == 1)
		{
			ft_free((void **)&input);
			break ;
		}
		input_joined = ft_strjoin(input_joined, input, 1);
		if (!input_joined)
			check_and_f_if_exist("h_doc:str_join", data, input_joined, input);
		ft_free((void **)&input);
	}
	return (input_joined);
}

void	process_heredoc(t_data *data)
{
	char	*input;

	input = process_input(data);
	redirect_fd_file(&input, data);
}

void	init_data(char **argv, int ac, char **envp, t_data *data)
{
	ft_memset((void *)data, 0, sizeof(t_data));
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (ac > 6)
			check_and_f_if_exist("incorrect arg here_doc", data, NULL, NULL);
		data->limiter = argv[2];
		data->nb_command = ac - 4;
		process_heredoc(data);
		data->input_file = HERE_DOC_FILE;
	}
	else
	{
		if (ac < 5)
			check_and_f_if_exist("incorrect ac nb", data, NULL, NULL);
		data->input_file = argv[1];
		data->nb_command = ac - 3;
	}
	data->prev_pipe = -1;
	data->envp = envp;
	data->env_paths = search_path(data);
	data->output_file = argv[ac - 1];
	data->pid = (int *)malloc(data->nb_command * sizeof(int));
	if (!data->pid)
		check_splits_free(MALLOC_FAILED, NULL, data, 0);
}

/*
on doit chercher le path 
rassembler tout les donnner
compter le nombre de commandes
et faire attemtion au here_doc
*/