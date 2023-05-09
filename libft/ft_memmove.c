/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:41:50 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/17 00:54:04 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			((char *) dst)[len] = ((char *) src)[len];
	return (dst);
}

// int main()
// {
// 	char	a[21] = "111000111000";

//     printf("Before memmove a = %s\n", a);
// 	ft_memmove(a+3, a, 6);
//     printf("After memmove a = %s\n", a);
//    return(0);
// }
