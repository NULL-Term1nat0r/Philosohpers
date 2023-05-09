/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:53:42 by estruckm          #+#    #+#             */
/*   Updated: 2023/01/07 13:59:07 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>

int	ft_isalpha(int chr)
{
	unsigned char	c;

	c = (unsigned char) chr;
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// int main()
// {
// 	char c, result;

//     c = '*';
//  	result = ft_isalpha(c);
//     printf("The result is %d\n", result);

//     c = 'g';
//  	result = ft_isalpha(c);
//     printf("The result is %d\n", result);

//     c = '+';
//  	result = ft_isalpha(c);
//     printf("The result is %d\n", result);

//  	return 0;
// }
