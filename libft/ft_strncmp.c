/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:12:17 by vali              #+#    #+#             */
/*   Updated: 2024/07/29 20:49:01 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length )
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < length - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
