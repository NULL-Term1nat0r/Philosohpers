/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:24:33 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/24 14:25:34 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/* including the data pointer to make everything gets
closed properly when the time creation fails
*/
u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	wait_time;

	wait_time = get_time() + time;
	while (get_time () <= wait_time)
		usleep(200);
	return (0);
}

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
