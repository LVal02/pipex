/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:33:32 by vali              #+#    #+#             */
/*   Updated: 2024/08/14 12:39:20 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		len;

	len = ft_strlen(str);
	dup = (char *)malloc(len + 1 * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, len + 1);
	return (dup);
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *ft_strdup(const char *str);

int main()
{
    const char *original = "Hello, world!";
    char *duplicate = ft_strdup(original);

    if (duplicate)
    {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate); // Don't forget to free the allocated memory
    }
    else
    {
        printf("Memory allocation failed\n");
    }

    return 0;
}
*/
