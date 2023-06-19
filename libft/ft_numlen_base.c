/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:04:02 by estruckm          #+#    #+#             */
/*   Updated: 2023/04/26 13:10:24 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen_base(unsigned long long n, size_t base)
{
	size_t	i;

	i = 1;
	while (n >= (unsigned long long)base)
	{
		n /= base;
		i++;
	}
	return (i);
}
