/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:04:29 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/20 00:32:53 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	output_error(char *str, t_data *data)
{
	pthread_mutex_lock(&data->write);
	printf("%s\n", str);
	pthread_mutex_lock(&data->dead);
	data->dead_check = 1;
	pthread_mutex_unlock(&data->dead);
	pthread_mutex_unlock(&data->write);
}

void	output_message(char *str, t_philis *philo, char *colour)
{
	u_int64_t	actual_time;


	pthread_mutex_lock(&philo->data->write);
	actual_time = get_time(philo->data) - philo->start_time;
	printf("%llu %d %s%s%s\n", actual_time, philo->id, colour, str, X);
	pthread_mutex_unlock(&philo->data->write);
}

void	output_message_exit(char *str, t_philis *philo)
{
	u_int64_t	actual_time;

	pthread_mutex_lock(&philo->data->write);
	actual_time = get_time(philo->data) - philo->start_time;
	printf("%llu %d %s\n", actual_time, philo->id, str);
	pthread_mutex_lock(&philo->data->dead);
	philo->data->dead_check = 1;
	pthread_mutex_unlock(&philo->data->dead);
}

void	life_circle(t_philis *philo)
{
	death_check(philo);
	if (philo->id % 2 != 0
		&& philo->data->death_time < 2 * philo->data->eat_time)
	{
		ft_usleep(philo->data->eat_time - philo->data->death_time, philo);
	}
	// if (philo->id % 2 != 0)
	// 	ft_usleep(philo->data->eat_time, philo);
	pthread_mutex_lock(philo->left_fork);
	death_check(philo);
	output_message(TAKE_FORK, philo, YELLOW);
	if (philo->id % 2 != 0
		&& philo->data->death_time < 2 * philo->data->eat_time)
	{
		ft_usleep(philo->data->eat_time - philo->data->death_time, philo);
	}
	// if (philo->id % 2 != 0)
	// 	ft_usleep(philo->data->eat_time, philo);
	pthread_mutex_lock(philo->right_fork);
	death_check(philo);
	output_message(TAKE_FORK, philo, YELLOW);
	philo->kill_time = get_time(philo->data) + philo->data->death_time;
	output_message(EATING, philo, GREEN);
	ft_usleep(philo->data->eat_time, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	meal_check(philo);
	output_message(SLEEPING, philo, BLUE);
	ft_usleep(philo->data->sleep_time, philo);
	output_message(THINKING, philo, RED);
}
