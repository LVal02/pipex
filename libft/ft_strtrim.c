/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:39:44 by vali              #+#    #+#             */
/*   Updated: 2024/05/25 15:24:35 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findindex(char c, char *tofind)
{
	int	i;

	i = 0;
	while (tofind && tofind[i])
	{
		if (c == tofind[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*new;
	int		i;
	int		j;

	if (!str || !set)
		return (NULL);
	i = 0;
	while (str && str[i] && findindex(str[i], (char *)set))
		i++;
	j = ft_strlen(str) - 1;
	while (str && j > i && str[j] && findindex(str[j], (char *)set))
		j--;
	new = ft_substr(str, i, j - i + 1);
	return (new);
}
/*
char	*ft_strtrim(char const *str, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	newstart;
	size_t	newstrlen;
	char	*newstr;

	i = 0;
	j = 0;
	newstrlen = ft_strlen(str);
	while (set[i])
	{
		if (set[i] == str[j])
		{
			j++;
			newstrlen--;
			i = 0;
		}
		i++;
	}
	newstart = j;
	i = 0;
	j = ft_strlen(set);
	while (set[i])
	{
		if (set[i] == str[j])
		{
			j--;
			newstrlen--;
			i = 0;
		}
		i++;
	}
	newstr = (char *)malloc(newstrlen + 1 * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < newstrlen)
	{
		newstr[i] = str[newstart + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
*/