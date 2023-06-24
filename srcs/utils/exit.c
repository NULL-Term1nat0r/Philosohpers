/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:46:40 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/20 15:39:55 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	clear_data_struct(t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->start_signal);
	pthread_mutex_destroy(&data->dead);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->meal);
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
}

void	clear_philo_struct(t_philis *philo, int i)
{
	while (i < philo->data->philo_num)
	{
		pthread_mutex_destroy(&philo[i].time);
		pthread_mutex_destroy(&philo[i].finished);
		pthread_mutex_destroy(&philo[i].kill_check);
		i++;
	}
}

void	catch_threads(t_data *data, int i)
{
	if (i == data->philo_num + 2)
		pthread_join(data->death_checker, NULL);
	if (i == data->philo_num + 3)
		pthread_join(data->meal_checker, NULL);
	while (i < data->philo_num)
	{
		pthread_join(data->tid[i], NULL);
		i++;
	}
}

void	ft_exit(t_data *data, int i)
{
	pthread_mutex_unlock(&data->write);
	catch_threads(data, i);
	clear_philo_struct(data->philo, i);
	clear_data_struct(data);
	if (data->tid)
		free(data->tid);
}
