/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: se <se@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:57:36 by vali              #+#    #+#             */
/*   Updated: 2024/08/01 16:08:16 by se               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = 0;
	while (dest[i] && i < size)
		i++;
	j = 0;
	while (src[j])
		j++;
	count = 0;
	if (size <= i)
		return (i + j);
	while (src[count] && (i + count) < size - 1)
	{
		dest[i + count] = src[count];
		count++;
	}
	if (size > i)
		dest[i + count] = '\0';
	return (i + j);
}
/*
#include <bsd/string.h>
#include <stdio.h>
#include <string.h> 
int     main(void)
{
char z[100] = "I am learn";
char b[100] = "learn";
char zz[100] = "I am learn";
char bb[100] = "learn";

// ft_strstr(z, b);
printf("texit: %s\n", z);
printf("result: %d\n", ft_strlcat(z, b,14));
printf("text: %s\n", z);
printf("textSTRLCAT: %s\n", zz);
printf("resultSTRLCAT: %zu\n", strlcat(zz, bb,14));
printf("textSTRLCAT: %s`\n", zz);

return (0);
}*/
