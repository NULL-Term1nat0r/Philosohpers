/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:30:26 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 18:55:52 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>
//#include "libft.h"

int	ft_isdigit(int chr)
{
	unsigned char	c;

	c = (unsigned char) chr;
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int main ()
// {
// 	int a;
// 	int b;
// 	b = 'c';
// 	a = '6';
// 	printf(" test1: %d", isdigit(a));
// 	printf(" test2: %d", isdigit(b));
// 	printf(" test1: %d/n", ft_isdigit(a));
// 	printf(" test2: %d", ft_isdigit(b));

// 	return 0;

// }
