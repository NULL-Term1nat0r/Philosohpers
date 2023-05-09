/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:59:10 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/23 20:09:50 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

//  int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (s1[i] != s2[i])
// 			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
// 		if (s1[i] == '\0' || s2[i] == '\0')
// 			return (0);
// 		i++;
// 	}
// 	return (0);
// }

//  int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*s1 && *s2 && i < n)
// 	{
// 		if (*s1 != *s2)
// 			return (*(unsigned char *)s1 - *(unsigned char *)s2);
// 		++s1;
// 		++s2;
// 		++i;
// 	}
// 	if (i == n)
// 	{
// 		--s1;
// 		--s2;
// 	}
// 	return (*(unsigned char *)s1 - *(unsigned char *)s2);
// }

// int main () {
//    char str1[] = "";
//    char str2[] = "";
//    size_t result;

//    strcpy(str1, "AAAAAAA");
//    strcpy(str2, "");

// //    //This will compare the first 4 characters
//    result = strncmp("testss", "test", 7);
// //    result_2 = ft_strncmp("testtest", "test", 3);
// 	printf("result: %lu", result);

//    return 0;
// }
