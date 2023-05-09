/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:08:03 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 19:07:17 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}
// int main ()
// {
//  /* Create a place to store our results */
//     /* Create two arrays to hold our data */
//     char original[6] = "";
// 	char original_2[6] = "";
//     char newcopy[] = "elefant";

// 	ft_memcpy(original, newcopy, 3);
// 	ft_memcpy(original_2, newcopy, 3);

// 	printf("ergebnis nach ft_memcpy: %s\n", original);
// 	printf("ergebnis nach    memcpy: %s\n", original_2);

// 	return 0;

// }
