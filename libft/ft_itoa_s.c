/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:27:58 by estruckm          #+#    #+#             */
/*   Updated: 2023/04/10 17:28:03 by estruckm         ###   ########.fr       */
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

char	*ft_itoa_s(int n, char *buf)
{
	int		len_n;

	len_n = ft_numlen(n, 10);
	if (n < 0)
	{
		buf[0] = '-';
		n *= -1;
	}
	if (n == 0)
		buf[0] = '0';
	ft_numstorage(len_n, n, buf);
	return (buf);
}
