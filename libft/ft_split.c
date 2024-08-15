/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:41:00 by vali              #+#    #+#             */
/*   Updated: 2024/05/24 20:38:47 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *str, char c)
{
	int	count;
	int	inword;
	int	i;

	count = 0;
	inword = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && !inword)
		{
			inword = 1;
			count++;
		}
		else if (str[i] == c)
			inword = 0;
	i++;
	}
	return (count);
}

static void	freememsetstr(char **setstr)
{
	int	i;

	i = 0;
	while (setstr[i])
	{
		free(setstr[i]);
		i++;
	}
	free(setstr);
}

char	**createsetstr(char const *str, char c, char **setstr)
{
	int	k;
	int	len;

	k = 0;
	while (*str)
	{
		if (*str != c)
		{
			len = 0;
			while (*str && *str != c && ++len)
				str++;
			setstr[k] = ft_substr((str - len), 0, len);
			if (!setstr[k])
			{
				freememsetstr(setstr);
				return (NULL);
			}
			k++;
		}
		else
			str++;
	}
	setstr[k] = NULL;
	return (setstr);
}

char	**ft_split(char const *str, char c)
{
	char	**setstr;

	if (!str)
		return (NULL);
	setstr = (char **) malloc((countwords(str, c) + 1) * sizeof(char *));
	if (!setstr)
		return (NULL);
	setstr = createsetstr(str, c, setstr);
	if (!setstr)
	{
		free(setstr);
		return (NULL);
	}
	return (setstr);
}
