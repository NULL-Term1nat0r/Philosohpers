/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:10:07 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/20 00:32:23 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void *philo_struct)
{
	t_philis	*philo;

	philo = (t_philis *)philo_struct;
	pthread_mutex_lock(&philo->data->start_signal);
	pthread_mutex_unlock(&philo->data->start_signal);
	philo->kill_time = get_time(philo->data) + philo->data->death_time;
	philo->start_time = get_time(philo->data);
	if (philo->id % 2 == 0)
		usleep(2000);
	while (philo->data->dead_check != 1)
	{
		life_circle(philo);
	}
	return ((void *)0);
}

int	thread_init(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->start_signal);
	while (i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philo[i]))
			output_error("thread creation failed\n", data);
		i++;
	}
	pthread_mutex_unlock(&data->start_signal);
	return (0);
}

//--tool=helgrind
