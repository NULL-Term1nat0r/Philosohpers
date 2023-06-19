/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:57:45 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 18:53:26 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

// cc ft_calloc.c ft_bzero.c ft_memset.c

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(size * count);
	if (!p)
		return (0);
	ft_bzero(p, size * count);
	return (p);
}

// int main() {
//     int i, * ptr, sum = 0;
//     ptr = ft_calloc(4, 4);
//     if (ptr == NULL) {
//         printf("Error! memory not allocated.");
//         exit(0);
//     }
//     printf("Building and calculating the sequence
//sum of the first 10 terms \n ");
//     for (i = 0; i < 10; ++i) { * (ptr + i) = i;
//         sum += * (ptr + i);
//     }
//     printf("Sum = %d", sum);
//     free(ptr);
//     return 0;
// }
