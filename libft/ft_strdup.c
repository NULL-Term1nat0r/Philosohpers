/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:39:43 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/26 13:06:10 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;

	if (*s1 == '\0')
	{
		p = ft_calloc(1, 1);
		return (p);
	}
	p = ft_calloc(1, ft_strlen(s1) + 1);
	if (p == 0)
		return (0);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}
// int main ()
// {
// 	return 0;
// }
