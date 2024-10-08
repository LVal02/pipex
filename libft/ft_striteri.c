/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:14:28 by vali              #+#    #+#             */
/*   Updated: 2024/05/24 14:14:29 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (str[i])
	{
		(*f)(i, &str[i]);
		i++;
	}
}
