/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:16:37 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 19:03:45 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s1_1;
	unsigned char	*s2_2;

	i = 0;
	s1_1 = (unsigned char *) s1;
	s2_2 = (unsigned char *) s2;
	while (n != 0)
	{
		if (s1_1[i] != s2_2[i])
			return (s1_1[i] - s2_2[i]);
		i++;
		n--;
	}
	return (0);
}

// int main ()
// {
// 	char str_1[] ="";
// 	char str_2[] ="";

// 	int result_1;
// 	int result_2;

// 	result_1 = memcmp(str_1, str_2, 1);
// 	result_2 = ft_memcmp(str_1, str_2, 1);

// 	printf("Ergebnis von memcmp: %d\n", result_1);
// 	printf("Ergebnis von ft_memcmp: %d\n", result_2);

// 	return 0;
// }
