/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:23:53 by vali              #+#    #+#             */
/*   Updated: 2024/08/14 12:38:16 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **argv, char **envp)
{
	t_data	data;

	if (ac < 5)
		return (1);
	init_data(argv, ac, envp, &data);
	process_fork(&data, argv, 2 + (data.limiter != NULL));
	check_splits_free(NULL, NULL, &data, 0);
	return (0);
}
