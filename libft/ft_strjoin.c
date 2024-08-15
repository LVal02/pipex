/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: se <se@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:38:40 by vali              #+#    #+#             */
/*   Updated: 2024/08/05 01:17:58 by se               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int needtofree_s1)
{
	size_t	ttlen;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	ttlen = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(ttlen + 1 * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(newstr, s2, ttlen + 1);
	if (needtofree_s1)
		ft_free((void **)&s1);
	return (newstr);
}
