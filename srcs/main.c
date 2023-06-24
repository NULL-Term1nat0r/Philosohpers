/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:22:41 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/19 23:47:56 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	death_check(t_philis *philo)
{
	pthread_mutex_lock(&philo->kill_check);
	if (philo->kill_time <= get_time(philo->data))
	{
		philo->dead_status = 1;
		output_message_exit(DYING, philo);
	}
	pthread_mutex_lock(&philo->kill_check);
}
//
//void	meal_check(t_philis *philo)
//{
//	philo->eat_count++;
//	if (philo->eat_count == philo->data->meals_num)
//	{
//		pthread_mutex_lock(&philo->data->meal);
//		philo->data->finished++;
//		if (philo->data->finished == philo->data->philo_num)
//			output_message_exit(FINISHED, philo);
//		pthread_mutex_unlock(&philo->data->meal);
//	}
//}

int death_check_test(t_philis *philo)
{
	int i;

	i = 0;
	while (i < philo->data->philo_num)
	{
		pthread_mutex_lock(&philo->data->philo[i].kill_check);
		if (philo->data->philo[i].dead_status == 1)
			return (1);
		pthread_mutex_unlock(&philo->data->philo[i].kill_check);
		i++;
	}
	return (0);
}

int death_check_main(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i].kill_check);
		if (data->philo[i].kill_time <= get_time(data))
		{
			output_message_exit(DYING, &data->philo[i]);
			while (j < data->philo_num)
			{
				if (j != i)
					pthread_mutex_lock(&data->philo[j].kill_check);
				data->philo[i].dead_status = 1;
				pthread_mutex_unlock(&data->philo[j].kill_check);
				j++;
			}
			return (1);
		}
		pthread_mutex_unlock(&data->philo[i].kill_check);
		i++;
	}
	return (0);
}

int meal_check_main(t_data *data)
{
	int i;
	int number_check;

	i = 0;
	number_check = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i].finished);
		if (data->philo[i].eat_count == data->meals_num)
			number_check++;
		pthread_mutex_unlock(&data->philo[i].finished);
		i++;
	}
	if (number_check == data->philo_num)
	{
		output_message_finished(FINISHED, data);
		return (1);
	}
	return (0);
}

void	case_one(t_data *data)
{
	printf("0 1 has taken a fork\n");
	usleep(data->death_time);
	printf("%llu 1 died\n", data->death_time);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_all_structs(&data, argc, argv) == 1)
		return (0);
	if (ft_atoi(argv[1]) == 1)
		case_one(&data);
	else
	{
		thread_init(&data);
		pthread_mutex_lock(&data.dead);
		while (data.dead_check == 0)
		{
			pthread_mutex_unlock(&data.dead);
			usleep(200);
		}
		pthread_mutex_unlock(&data.dead);
	}
	if (ft_atoi(argv[1]) != 1)
		ft_exit(&data);
	return (0);
}
