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

void	*meal_checker(void *data_struct)
{
	t_data	*data;

	data = (t_data *)data_struct;
	usleep(1000);
	pthread_mutex_lock(&data->dead);
	while (data->dead_check == 0)
	{
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
			if (data->philo[i].kill_time < get_time(data))
			{
				death_execution(data, i);
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
	philo->kill_time = get_time(philo->data) + philo->data->death_time;
	pthread_mutex_unlock(&philo->kill_check);
	pthread_mutex_lock(&philo->time);
	philo->start_time = get_time(philo->data);
	pthread_mutex_unlock(&philo->time);
	pthread_mutex_lock(&philo->data->start_signal);
	pthread_mutex_unlock(&philo->data->start_signal);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time / 2, philo);
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
		{
			ft_exit(data, i);
			return (i);
		}
		i++;
	}
	pthread_mutex_unlock(&data->start_signal);
	if (pthread_create(&data->death_checker, NULL, &death_checker, data))
	{
		ft_exit(data, i + 1);
		return (i + 1);
	}
	if (pthread_create(&data->meal_checker, NULL, &meal_checker, data))
	{
		ft_exit(data, i + 2);
		return (i + 2);
	}
	return (i + 3);
}
