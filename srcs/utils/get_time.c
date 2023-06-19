/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:24:33 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/19 22:32:27 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/* including the data pointer to make everything gets
closed properly when the time creation fails
*/
u_int64_t	get_time(t_data *data)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		output_error("gettimeoftheday function has failed\n", data);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(useconds_t time, t_philis *philo)
{
	u_int64_t	wait_time;

	wait_time = get_time(philo->data) + time;
	while (get_time (philo->data) <= wait_time)
	{
		death_check(philo);
		usleep(200);
	}
	return (0);
}
