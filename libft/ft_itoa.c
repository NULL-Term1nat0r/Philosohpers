/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:09:22 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/26 12:38:20 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_numlen(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= base;
	return (count);
}

static char	*ft_numstorage(int len, int num, char *array_2)
{
	while (len--, num > 0)
	{
		array_2[len] = num % 10 + '0';
		num = num / 10;
	}
	return (array_2);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		len_n;

	len_n = ft_numlen(n, 10);
	array = malloc(sizeof(char) * (len_n + 1));
	if (array == 0)
		return (NULL);
	array[len_n] = '\0';
	if (n < 0)
	{
		array[0] = '-';
		if (n == -2147483648)
		{
			array[--len_n] = '8';
			n /= 10;
		}
		n *= -1;
	}
	if (n == 0)
		array[0] = '0';
	array = ft_numstorage(len_n, n, array);
	return (array);
}

// int main ()
// {
// 	char* str;

// 	str = ft_itoa(9887);
// 	printf("Ergebnis: 			%s\n", str);
// 	printf("Ergebnis count:		%d\n", ft_numlen(100, 10));
// 	return 0;
// }
