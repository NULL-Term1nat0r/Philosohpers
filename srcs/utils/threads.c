/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:10:07 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/20 15:26:48 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void *death_checker(void *data_struct)
{
	t_data *data;
	int i;
	u_int64_t	actual_time;

	i = 0;
	data = (t_data *)data_struct;
	while (69)
	{
		i = 0;
		while (i < data->philo_num)
		{
			pthread_mutex_lock(&data->philo[i].kill_check);
			if (data->philo[i].kill_time < get_time(data))
			{
				pthread_mutex_unlock(&data->philo[i].kill_check);
				pthread_mutex_lock(&data->write);
				if (data->write_check == 0)
				{
					actual_time = get_time(data) - data->start_time;
					printf("%llu %d %s\n", actual_time, data->philo[i].id, DYING);
				}
				data->write_check = 1;
				pthread_mutex_unlock(&data->write);
				pthread_mutex_lock(&data->dead);
				actual_time = get_time(data) - data->start_time;
				data->dead_check = 1;
				pthread_mutex_unlock(&data->dead);
				return ((void *)0);
			}
			pthread_mutex_unlock(&data->philo[i].kill_check);
			i++;
		}
		usleep(20);
	}
}

void *meal_checker(void *data_struct)
{
	t_data *data;
	int i;
	int count;

	data = (t_data *)data_struct;
	pthread_mutex_lock(&data->dead);
	while (data->dead_check == 0)
	{
		pthread_mutex_unlock(&data->dead);
		i = 0;
		count = 0;
		while (i < data->philo_num)
		{
			pthread_mutex_lock(&data->philo[i].finished);
			if (data->philo[i].eat_count == data->meals_num)
				count++;
			pthread_mutex_unlock(&data->philo[i].finished);
			i++;
		}
		if (count == data->philo_num)
		{
			pthread_mutex_lock(&data->write);
			if (data->write_check == 0)
				printf("Every Philosopher has eaten at least one time\n");
			data->write_check = 1;
			pthread_mutex_unlock(&data->write);
			pthread_mutex_lock(&data->dead);
			data->dead_check = 1;
			pthread_mutex_unlock(&data->dead);
			break;
		}
		usleep(20);
		pthread_mutex_lock(&data->dead);
	}
	pthread_mutex_unlock(&data->dead);
	return ((void *)0);
}

void	*routine(void *philo_struct)
{
	t_philis	*philo;

	philo = (t_philis *)philo_struct;
	philo->kill_time = get_time(philo->data) + philo->data->death_time;
	pthread_mutex_lock(&philo->data->start_signal);
	pthread_mutex_unlock(&philo->data->start_signal);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time/2, philo);
	pthread_mutex_lock(&philo->data->dead);
	while (philo->data->dead_check == 0)
	{
		pthread_mutex_unlock(&philo->data->dead);
		life_circle(philo);
		pthread_mutex_lock(&philo->data->dead);
	}
	pthread_mutex_unlock(&philo->data->dead);
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
	if (pthread_create(&data->death_checker, NULL, &death_checker, data))
		output_error("thread creation failed\n", data);
	if (pthread_create(&data->meal_checker, NULL, &meal_checker, data))
		output_error("thread creation failed\n", data);
	data->start_time = get_time(data);
	pthread_mutex_unlock(&data->start_signal);

	return (0);
}

//--tool=helgrind
