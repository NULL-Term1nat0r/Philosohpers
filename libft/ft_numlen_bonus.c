/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:40:59 by estruckm          #+#    #+#             */
/*   Updated: 2022/12/21 16:41:36 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && count++)
		n /= base;
	return (count);
}
