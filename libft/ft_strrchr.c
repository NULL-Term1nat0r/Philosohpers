/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:01:49 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 20:00:28 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ret = (char *)s;
		++s;
	}
	if (!c)
		ret = ((char *)s);
	return (ret);
}

// int main ()
// {
//    const char str[] = "soinfso.oifnosi.sd";
//    const char ch = '.';
//    char *ret;

//    ret = strrchr(str, ch);

//    printf("String after |%c| is - |%s|\n", ch, ret);

// 	ret = ft_strrchr(str, ch);
// 	 printf("String after |%c| is - |%s|\n", ch, ret);
//    return(0);
// }
