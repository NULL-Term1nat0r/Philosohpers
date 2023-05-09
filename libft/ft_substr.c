/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:34:14 by estruckm          #+#    #+#             */
/*   Updated: 2023/04/10 17:28:56 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*p;

// 	if (s == 0)
// 		return (0);
// 	if (ft_strlen(s) < start)
// 		len = 0;
// 	if (ft_strlen(s + start) < len)
// 		len = ft_strlen(s + start);
// 	p = malloc((len + 1));
// 	if (p == 0)
// 		return (NULL);
// 	ft_strlcpy(p, s + start, len +1);
// 	return (p);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (ft_strlen(s) < start || s == NULL)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
