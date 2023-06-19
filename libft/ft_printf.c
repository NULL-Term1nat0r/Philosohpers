/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:49:44 by estruckm          #+#    #+#             */
/*   Updated: 2023/04/26 13:18:38 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Variadic function to add numbers
int	ft_printf(const char *s, ...)
{
	va_list			arguments;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (s[i] == '\0')
		return (0);
	va_start(arguments, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]) != 0)
		{
			j += ft_flagcheck(s[i + 1], arguments);
			i++;
		}
		else
			j += ft_putchar_printf(s[i]);
		i++;
	}
	va_end(arguments);
	return (j);
}

//quelle zur Aufsetzung und edge cases
// https://hector.dev.br/2021/09/15/ft-printf/
