/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:51:32 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/21 16:53:40 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_data_struct(t_data *data)
{
	int	i;

	i = 0;
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	data->philo = malloc(sizeof(t_philis) * data->philo_num);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	data->dead_check = 0;
	data->write_check = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->meal, NULL);
	pthread_mutex_init(&data->start_signal, NULL);
	pthread_mutex_init(&data->dead, NULL);
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_struct_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->philo[i].kill_check, NULL);
		pthread_mutex_init(&data->philo[i].finished, NULL);
		data->philo[i].data = data;
		data->philo[i].dead_status = 0;
		data->philo[i].eat_count = 0;
		data->philo[i].id = i + 1;
		data->philo[i].left_fork = &data->forks[i];
		if (i != 0)
			data->philo[i].right_fork = &data->forks[i - 1];
		else
			data->philo[i].right_fork = &data->forks[data->philo_num - 1];
		i++;
	}
}

int	init_all_structs(t_data *data, int argc, char **argv)
{
	if (get_input(data, argc, argv) == 0)
	{
		init_data_struct(data);
		init_struct_philo(data);
		return (0);
	}
	else
		return (1);
}
