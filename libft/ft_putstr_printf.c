/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:00 by estruckm          #+#    #+#             */
/*   Updated: 2023/04/26 13:17:27 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_printf(char *s)
{
	int				i;
	unsigned char	c;

	i = 0;
	if (s == 0)
		return (write(1, "(null)", 6));
	while (*s != '\0')
	{
		c = *s;
		i += write(1, &c, 1);
		s++;
	}
	return (i);
}

// int main ()
// {
// 	char test[4] = "1234";
// 	printf("%s\n", test);
// }
