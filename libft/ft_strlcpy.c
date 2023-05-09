/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:48:32 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 20:10:03 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

// int main()
// {
// 	size_t result;
// 	size_t result_2;
//  	char src[10] = "ffff";
// 	char dst[20] = "";

// 	char src_2[10] = "ffff";
// 	char dst_2[20] = "";
// 	//strlcpy(dst, src, 2);
// 	result = strlcpy(dst, src, 0);
// 	strlcpy(dst, src, 3);
// 	printf("After strlcpy(): %s\n", dst);
// 	printf("Wert: %zu\n\n", result);

// 	result_2 = ft_strlcpy(dst_2, src_2, 0);
// 	ft_strlcpy(dst_2, src_2, 3);
// 	printf("After ft_strlcpy(): %s\n", dst_2);
// 	printf("Wert: %zu", result_2);

// 	return 0;
// }
