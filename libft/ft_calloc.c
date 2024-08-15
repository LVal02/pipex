/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vali <vali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:38:57 by vali              #+#    #+#             */
/*   Updated: 2024/05/27 21:44:38 by vali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	mem = (void *)malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
/*
#define NUM_ELEMENTS ((size_t)2147483649) 
int	main(void)
{
	
	int *A;
	int *B;
	size_t	i;
	size_t	max;

	max = 3094967296;
	A = ft_calloc(max + 1, sizeof *A);
	B = malloc(max + 1 * sizeof *A);
	
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("count: %zu bytes\n", max);
    printf("SIZE_MAX / size: %lu bytes\n", SIZE_MAX / sizeof(int));
	// Add size check
	if (!A && NUM_ELEMENTS != 0) {
		fputs("mem failure in my ft_malloc, exiting \n", stderr);
	}
	else
	{
		i = 1;
		printf("%d ", A[max]);
		A[max] = i;
		printf("%d ", A[max]);
		printf("\n");
	}
	if (!B && NUM_ELEMENTS != 0) {
		fputs("mem failure, exiting \n", stderr);
	}
	
	return (0);
}

*/