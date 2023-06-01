/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:51:32 by estruckm          #+#    #+#             */
/*   Updated: 2023/05/29 21:29:31 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void init_data_struct(t_data *data, int argc, char **argv)
{
	int i;

	i = 0;
	get_input(data, argc, argv);
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	data->philo = malloc(sizeof(t_philis) * data->philo_num);
	data->forks = malloc(sizeof(pthread_mutex_t) *data->philo_num);
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void init_struct_philo(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->philo[i].lock, NULL);
		data->philo[i].data = data;
    	data->philo[i].eat_count = 0;
    	data->philo[i].kill_time = data->death_time;
    	data->philo[i].eat_status = 0;
    	data->philo[i].id = i + 1;
		data->philo[i].left_fork = &data->forks[i];
		if (i != 0)
			data->philo[i].right_fork = &data->forks[i - 1];
		else
			data->philo[i].right_fork = &data->forks[data->philo_num - 1];
		// if (pthread_create(&data->tid[i], NULL, eating, &data->philo[i]))
		// 	printf("created of thread failed");
		i++;
	}
}

void init_all_structs(t_data *data, int argc, char **argv)
{
	init_data_struct(data, argc, argv);
	init_struct_philo(data);
}
