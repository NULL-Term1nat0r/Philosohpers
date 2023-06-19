/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:12:37 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 18:53:46 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>
#include "libft.h"

int	ft_isalnum(int chr)
{
	unsigned char	c;

	c = (unsigned char) chr;
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
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
// 	int c;
// 	b = 'c';
// 	a = '6';
// 	c = '/';

// 	printf(" test1: %d", isalnum(a));
// 	printf(" test2: %d", isalnum(b));
// 	printf(" test2: %d", isalnum(c));
// 	printf(" test1: %d/n", ft_isalnum(a));
// 	printf(" test2: %d", ft_isalnum(b));
// 	printf(" test2: %d", ft_isalnum(c));

// 	return 0;

// }
