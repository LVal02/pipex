/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:57:20 by vali              #+#    #+#             */
/*   Updated: 2024/05/22 15:11:39 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *mem, const void *memtocmp, size_t n)
{
	const unsigned char	*dup;
	const unsigned char	*duptocmp;
	size_t				i;

	i = 0;
	dup = (const unsigned char *)mem;
	duptocmp = (const unsigned char *)memtocmp;
	while (i < n)
	{
		if (dup[i] != duptocmp[i])
			return (dup[i] - duptocmp[i]);
		i++;
	}
	return (0);
}
