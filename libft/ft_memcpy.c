/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:27:06 by vali              #+#    #+#             */
/*   Updated: 2024/05/21 16:51:35 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dupdest;
	unsigned char	*dupsrc;

	dupdest = (unsigned char *)dest;
	dupsrc = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (n--)
		dupdest[n] = dupsrc[n];
	return (dest);
}
