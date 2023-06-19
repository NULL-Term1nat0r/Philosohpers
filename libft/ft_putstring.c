/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:14:14 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/19 17:47:19 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstring(char *s)
{
	int	strlen;

	if (!s)
		return ;
	strlen = ft_strlen(s);
	write(1, s, strlen);
	write(1, "\n", 1);
}
