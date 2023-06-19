/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:25:20 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/12 13:44:33 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
// 	b = '6';
// 	a = '6';
// 	c = '/';

// 	printf(" test1: %d", isascii(a));
// 	printf(" test2: %d", isascii(b));
// 	printf(" test2: %d", isascii(c));
// 	printf(" test1: %d/n", ft_isascii(a));
// 	printf(" test2: %d", ft_isascii(b));
// 	printf(" test2: %d", ft_isascii(c));

// 	return 0;

// }
