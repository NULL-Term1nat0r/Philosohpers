/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:10:07 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/24 13:54:25 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*meal_checker(void *data_struct)
{
	t_data	*data;

	data = (t_data *)data_struct;
	usleep(1000);
	pthread_mutex_lock(&data->dead);
	while (data->dead_check == 0)
	{
		pthread_mutex_unlock(&data->dead);
		if (eat_counter(data) == 1)
			return ((void *)0);
		usleep(20);
		pthread_mutex_lock(&data->dead);
	}
	pthread_mutex_unlock(&data->dead);
	return ((void *)0);
}

void	*death_checker(void *data_struct)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)data_struct;
	usleep(1000);
	while (69)
	{
		i = 0;
		while (i < data->philo_num)
		{
			pthread_mutex_lock(&data->philo[i].kill_check);
			if (data->philo[i].kill_time < get_time())
			{
				death_execution(data, i);
				pthread_mutex_unlock(&data->philo[i].kill_check);
				return ((void *)0);
			}
			pthread_mutex_unlock(&data->philo[i].kill_check);
			i++;
		}
		usleep(20);
	}
}

void	*routine(void *philo_struct)
{
	t_philis	*philo;

	philo = (t_philis *)philo_struct;
	pthread_mutex_lock(&philo->kill_check);
	philo->kill_time = get_time() + philo->data->death_time;
	pthread_mutex_unlock(&philo->kill_check);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time / 2);
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
	data->start_time = get_time();
	while (i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philo[i]))
			return (ft_exit(data, i), 1);
		i++;
	}
	pthread_mutex_unlock(&data->start_signal);
	if (pthread_create(&data->death_checker, NULL, &death_checker, data))
		return (ft_exit(data, i), 1);
	if (data->meals_num != -1)
		if (pthread_create(&data->meal_checker, NULL, &meal_checker, data))
			return (ft_exit(data, i + 1), 1);
	return (0);
}
