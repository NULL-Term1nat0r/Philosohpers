/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:10:07 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/10 15:24:11 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void *routine(void *philo_struct)
{
	t_philis *philo;

	philo = (t_philis *)philo_struct;
	pthread_mutex_lock(&philo->data->start_signal);
	pthread_mutex_unlock(&philo->data->start_signal);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time);
	while (69)
	{
		life_circle(philo);
	}
	return ((void *)0);
}

int thread_init(t_data *data)
{
	int i;

	i = 0;
	pthread_mutex_lock(&data->start_signal);
	while (i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philo[i]))
			return 1;
		i++;
	}
	data->start_time = get_time();
	pthread_mutex_unlock(&data->start_signal);
	return (0);
}

void catch_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(data->tid[i], NULL);
		i++;
	}
}
