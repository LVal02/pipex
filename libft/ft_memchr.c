/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:34:52 by vali              #+#    #+#             */
/*   Updated: 2024/05/22 14:39:46 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int tocmp, size_t size)
{
	while (size)
	{
		if (*(char *)str == (char)tocmp)
			return ((void *)str);
		str++;
		size--;
	}
	return (NULL);
}
