/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:17:42 by vali              #+#    #+#             */
/*   Updated: 2024/05/24 20:39:55 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intstrmemsize(int nb, int *sign)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		*sign = -1;
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*ft_addnb(int value, char *str, long lgth, int *sign)
{
	str[lgth] = '\0';
	if (value < 0)
		value = -value;
	while (lgth > 0)
	{
		str[--lgth] = (value % 10) + '0';
		value = value / 10;
	}
	if (*sign < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int value)
{
	int		sizemem;
	int		sign;
	char	*memstr;

	sign = 1;
	sizemem = ft_intstrmemsize(value, &sign);
	if (value == 0)
		return (ft_strdup("0"));
	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	memstr = (char *)malloc(sizemem + 1 * sizeof(char));
	if (!memstr)
		return (NULL);
	return (ft_addnb(value, memstr, (long)sizemem, &sign));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(-10));
}
*/
