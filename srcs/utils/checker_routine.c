/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:04:30 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/24 13:54:53 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	eat_counter(t_data *data)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i].finished);
		if (data->philo[i].eat_count >= data->meals_num)
			count++;
		pthread_mutex_unlock(&data->philo[i].finished);
		i++;
	}
	if (count == data->philo_num)
	{
		meal_execution(data);
		return (1);
	}
	return (0);
}

void	meal_execution(t_data *data)
{
	pthread_mutex_lock(&data->write);
	if (data->write_check == 0)
		printf("Every Philosopher has eaten at least one time\n");
	data->write_check = 1;
	pthread_mutex_unlock(&data->write);
	pthread_mutex_lock(&data->dead);
	data->dead_check = 1;
	pthread_mutex_unlock(&data->dead);
}

void	death_execution(t_data *data, int i)
{
	u_int64_t	actual_time;

	pthread_mutex_lock(&data->write);
	if (data->write_check == 0)
	{
		actual_time = get_time() - data->start_time;
		printf("%llu %d %s\n", actual_time, data->philo[i].id, DYING);
	}
	data->write_check = 1;
	pthread_mutex_unlock(&data->write);
	pthread_mutex_lock(&data->dead);
	data->dead_check = 1;
	pthread_mutex_unlock(&data->dead);
}
