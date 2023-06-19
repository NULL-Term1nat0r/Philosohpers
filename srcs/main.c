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
	if (philo->kill_time <= get_time(philo->data))
		output_message_exit(DYING, philo);
}

void	meal_check(t_philis *philo)
{
	philo->eat_count++;
	if (philo->eat_count == philo->data->meals_num)
	{
		pthread_mutex_lock(&philo->data->meal);
		philo->data->finished++;
		if (philo->data->finished == philo->data->philo_num)
			output_message_exit(FINISHED, philo);
		pthread_mutex_unlock(&philo->data->meal);
	}
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

	init_all_structs(&data, argc, argv);
	if (ft_atoi(argv[1]) == 1)
		case_one(&data);
	else
	{
		thread_init(&data);
		while (data.dead_check != 1)
			usleep(2000);
	}
	if (ft_atoi(argv[1]) != 1)
		ft_exit(&data);
	return (0);
}
