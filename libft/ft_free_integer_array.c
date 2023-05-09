/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_integer_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:24:18 by estruckm          #+#    #+#             */
/*   Updated: 2023/04/10 17:27:38 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_free_integer_array(int **array, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(array[i++]);
	free(array);
}
