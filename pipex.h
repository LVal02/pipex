/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:23:44 by vali              #+#    #+#             */
/*   Updated: 2024/08/14 12:41:07 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# define HERE_DOC_FILE "pipex_heredoc_input.txt"
# define MALLOC_FAILED "syscall: malloc failed"
# define PIPE_FAILED "syscall: pipe failed"
# define FORK_FAILED "syscall: fork failed"
# define COMMAND_NOT_FOUND ": command not found"
# define EXECVE_FAILED "execve: failed"

typedef struct s_data
{
	char	**envp;
	char	**env_paths;
	char	**command;
	int		nb_command;
	pid_t	*pid;
	int		fd[2];
	int		prev_pipe;
	char	*input_file;
	char	*output_file;
	char	*command_path;
	char	*limiter;
}			t_data;

void		init_data(char **argv, int argc, char **envp, t_data *data);
void		check_and_f_if_exist(char *to_print, t_data *data, char *str1,
				char *str2);
void		check_splits_free(char *to_print, char **path, t_data *data,
				int freedata);
char		*assign_path_command(char *command, t_data *data);
char		**search_path(t_data *data);
void		redirect(t_data *data, int j);
void		process_fork(t_data *data, char **argv, int i);

#endif