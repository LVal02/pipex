/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:02:45 by vali              #+#    #+#             */
/*   Updated: 2024/05/24 16:44:07 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t		lenstr;
	size_t		j;
	char		*newstr;

	if (!str)
		return (NULL);
	lenstr = ft_strlen(str);
	if (len > lenstr - start)
		len = lenstr - start;
	if (start >= lenstr)
		return (ft_strdup(""));
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	j = 0;
	while (j < len)
	{
		newstr[j] = str[start + j];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}
