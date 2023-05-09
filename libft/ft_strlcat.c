/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:45:15 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 20:00:37 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[k])
		k++;
	if (dstsize <= i)
		k = k + dstsize;
	else
		k = k + i;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (k);
}
// int main()
// {
// 	size_t result_1;
// 	size_t result_2;
// 	char dst[20] = "abcdds";
// 	char dst_2[20] = "abcddds";

// 	result_1 = ft_strlcat(dst, "lorem ipsum dolor sit amet", 15);
// 	result_2 = strlcat(dst_2, "orem ipsum dolor sit amet", 15);
// 	printf("result: %lu\n", result_1);
// 	printf("After ft_strlcat(): %s\n", dst);
// 	printf("result: %lu\n", result_2);
// 	printf("After strlcat(): %s\n", dst_2);

// 	// result_2 = ft_strlcat(dst_2, src_2, 4);
// 	// ft_strlcat(dst_2, src_2, 4);
// 	// printf("After ft_strlcat): %s\n", dst_2);
// 	// printf("Wert: %zu", result_2);

// 	return 0;
// }
