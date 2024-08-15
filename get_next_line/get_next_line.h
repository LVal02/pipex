/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: se <se@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:16:32 by vali              #+#    #+#             */
/*   Updated: 2024/08/05 03:16:11 by se               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
// char	*ft_substr(char const *str, unsigned int start, size_t len);
// size_t	ft_strlen(const char *str);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strchr(const char *str, int tocmp);

#endif