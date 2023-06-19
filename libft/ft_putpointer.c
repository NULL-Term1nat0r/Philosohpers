/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:12:40 by estruckm          #+#    #+#             */
/*   Updated: 2023/04/26 13:19:28 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer(unsigned long n)
{
	int	i;

	i = 0;
	if ((long long)n == LONG_MIN)
	{
		write(1, "0x8000000000000000", 18);
		return (18);
	}
	if ((long long)n == LONG_MAX)
	{
		write(1, "0x7fffffffffffffff", 18);
		return (18);
	}
	ft_putstr_printf("0x");
	i += ft_puthex(n, "0123456789abcdef", 16) + 2;
	return (i);
}
