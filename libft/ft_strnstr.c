/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:46:10 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 20:00:33 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (NULL);
	if (!needle || !needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[j + i] && needle[j] && \
		haystack[j + i] == needle[j] && i + j < len)
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

// int main ()
// {
// 	char str_1[] = "aaaaahallo";
// 	char str_2[] = "hallo";

// 	printf("Ergebnis von strnstr:    %s\n", strnstr(str_1, str_2, 11));
// 	printf("Ergebnis von ft_strnstr: %s", ft_strnstr(str_1, str_2, 11));
// 	return 0;
// }
