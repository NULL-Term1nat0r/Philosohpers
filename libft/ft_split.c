/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:21:27 by estruckm          #+#    #+#             */
/*   Updated: 2023/03/23 15:50:40 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

// void	free_memory(char **array)
// {
// 	int	i;
//
// 	i = 0;
// 	if (array == NULL)
// 	{
// 		while (array[i] != NULL)
// 		{
// 			free(array[i]);
// 			i++;
// 		}
// 		free(array);
// 	}
// }
//
// int	ft_countchr(char const *s, char c)
// {
// 	int	i;
//
// 	i = 0;
// 	while (*s != '\0')
// 	{
// 		while (*s == c)
// 			s++;
// 		if (*s != '\0')
// 			i++;
// 		while (*s != c && *s != '\0')
// 				s++;
// 	}
// 	return (i);
// }
//
// char	**ft_split(const char *s, char c)
// {
// 	char	**ret;
// 	size_t	i;
// 	size_t	len;
//
// 	if (!s)
// 		return (0);
// 	i = 0;
// 	ret = malloc(sizeof(char *) * (ft_countchr(s, c) + 1));
// 	if (!ret)
// 		return (0);
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			len = 0;
// 			while (*s && *s != c && ++len)
// 				++s;
// 			ret[i++] = ft_substr(s - len, 0, len);
// 			free_memory(ret);
// 		}
// 		else
// 			++s;
// 	}
// 	ret[i] = 0;
// 	return (ret);
// }

static int	ft_count_char(const char *s, char c)
{
	unsigned int	i;
	int				count_c;

	i = 0;
	count_c = 0;
	while (s[i] == c && c != '\0')
		i++;
	if (s[i] == '\0')
		return (-1);
	while (s[i])
	{
		if (s[i] == c && i != 0)
		{
			count_c++;
			while (s[i] == c)
				i++;
			if (!s[i])
				count_c--;
		}
		else
			i++;
	}
	return (count_c);
}

// skips the delimiter char(s) in s and counts the lenght of the string
static void	ft_count(char const *s, char c, size_t *i_, size_t *len_)
{
	size_t	i;
	size_t	len;

	i = *i_;
	len = *len_;
	while (s[i] == c)
		i++;
	len = i;
	while (s[len] != c && s[len] != '\0')
		len++;
	*len_ = len;
	*i_ = i;
}

// free the array if there is an error while using substr
static char	**ft_free(char **sp_string)
{
	int	i;

	i = 0;
	while (sp_string[i])
	{
		free(sp_string[i]);
		i++;
	}
	free(sp_string);
	return (NULL);
}

// split the input string into multiple strings and
// returns them in a array of strings
char	**ft_split(char const *s, char c)
{
	size_t			i;
	size_t			len;
	char			**sp_string;
	int				index;

	index = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	sp_string = malloc (sizeof(char *) * (ft_count_char(s, c) + 2));
	if (sp_string == NULL)
		return (NULL);
	while (index < (ft_count_char(s, c) + 1))
	{
		ft_count(s, c, &i, &len);
		sp_string[index] = ft_substr(s, i, len - i);
		if (!sp_string[index])
			return (ft_free(sp_string));
		index++;
		i = len;
	}
	sp_string[index] = NULL;
	return (sp_string);
}
