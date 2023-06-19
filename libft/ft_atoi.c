/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:27:37 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/09 22:04:41 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	sign;
	int	temp;

	sign = 1;
	temp = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\v' || *str == '\r')
			str++;
	if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' \
	&& *str <= 'z') || *str == '\e')
		return (0);
	if (*str == '-')
		sign = -1;
	if (*str < '0' || *str > '9')
		str++;
	if ((*str < '0' && *str > '9') && *str != '-' && *str != '+' )
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		temp = (temp * 10) + (*str - '0');
		str++;
	}
	return (temp * sign);
}
// int main ()
// {
// 	int i;
// 	i = 0;
// 	const char str_1[] = "-21474836487";
// 	const char str_2[] = "";
// 	const char str_3[] = "\e\v3";
// 	const char str_4[] = "12h3";
// 	const char str_5[] = "00123";
// 	const char str_6[] = "123z56";
// 	const char str_7[] = "-0123hh";
// 	const char str_8[] = "\n\n123";
// 	const char str_9[] = "+--123";
// 	const char str_10[] = "−28";
// 	const char str_11[] = "test";

// 	const char *arr[] ={str_1, str_2, str_3, str_4, str_5,
// 		str_6, str_7, str_8, str_9, str_10, str_11};

// 	while (i != 11)
// 	{
// 		printf("Ergebnis atoi
//str_%-10d: %-10dErgebnis
//ft_atoi str_%-10d:%-10d \n", i+1,
//atoi(arr[i]), i+1, ft_atoi(arr[i]));
// 		i++;
// 	}

// 	return 0;
// }
