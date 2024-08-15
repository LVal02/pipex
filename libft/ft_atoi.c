/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:41:10 by vali              #+#    #+#             */
/*   Updated: 2024/05/20 15:46:26 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (((int)sign * result));
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char *arg[])
{
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		printf("myatoi:%d\n", ft_atoi("\007 8"));
		printf("notmyatoi:%d", atoi("\007 8"));
		(void)arg;
	}
	if (ac > 2)
		return (0);
	return (0);
}

*/