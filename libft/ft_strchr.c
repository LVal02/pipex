/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:44:59 by vali              #+#    #+#             */
/*   Updated: 2024/05/21 20:49:20 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int tocmp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)tocmp)
			return (((char *)&str[i]));
		i++;
	}
	if (str[i] == (char)tocmp)
		return ((char *)&str[i]);
	else
		return (NULL);
}
