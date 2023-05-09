/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:37:10 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 19:02:44 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_2;
	unsigned char	c_2;

	s_2 = (unsigned char *)s;
	c_2 = (unsigned char)c;
	while (n != 0)
	{
		if (*s_2 == c_2)
		{
			return (s_2);
		}
		n--;
		s_2++;
	}
	return (NULL);
}
//  int main () {
//    const char str[] = "";
//    const char ch = '.';
//    char *ret;
//    char *ret_2;

//    ret = memchr(str, ch, -3);
//    ret_2 = ft_memchr(str, ch, -3);

//    printf("String after |%c| is - |%s|\n", ch, ret);
//    printf("String after |%c| is - |%s|\n", ch, ret_2);

//    return(0);
// }
