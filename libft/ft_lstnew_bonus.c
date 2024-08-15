/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:49:31 by vali              #+#    #+#             */
/*   Updated: 2024/05/27 17:55:55 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*firstelem;

	firstelem = (t_list *)malloc(sizeof(t_list));
	if (!firstelem)
		return (NULL);
	firstelem->content = content;
	firstelem->next = NULL;
	return (firstelem);
}
