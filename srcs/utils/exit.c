/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:46:40 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 15:43:38 by estruckm         ###   ########.fr       */
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
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->meal);
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
}

void	clear_philo_struct(t_philis *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_num)
	{
		pthread_mutex_destroy(&philo[i].finished);
		pthread_mutex_destroy(&philo[i].kill_check);
		i++;
	}
}

void	catch_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_detach(data->tid[i]);
		pthread_join(data->tid[i], NULL);
		i++;
	}
}

void	ft_exit(t_data *data)
{
	clear_philo_struct(data->philo);
	clear_data_struct(data);
	catch_threads(data);
	if (data->tid)
		free(data->tid);
	exit(69);
}
