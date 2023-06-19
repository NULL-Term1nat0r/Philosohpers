/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:46:05 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/12 16:05:17 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_isprint(int chr)
{
	unsigned char	c;

	c = (unsigned char) chr;
	if (c >= ' ' && c <= '~')
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
// 	b = '';
// 	a = '6';
// 	printf(" test1: %d", isprint(a));
// 	printf(" test2: %d", isprint(b));
// 	printf(" test1: %d/n", ft_isprint(a));
// 	printf(" test2: %d", ft_isprint(b));

// 	return 0;

// }
