/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:36:47 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 19:08:43 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)b;
	while (len != 0)
	{
		*p = (unsigned char)c;
		p++;
		i++;
		len --;
	}
	return (p - i);
}
//  int main()
// {
//  	char str[100] = "Libc is the standard library.";

// 	ft_memset(str, '.', 15 * sizeof(char));
// 	printf("After memset(): %s\n", str);
// 	return 0;
// }
