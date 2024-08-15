/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:37:10 by vali              #+#    #+#             */
/*   Updated: 2024/05/27 17:46:32 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	char const	*last_req;

	last_req = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last_req = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return ((char *)last_req);
}
