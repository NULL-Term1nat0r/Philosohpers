/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:04:29 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/20 15:49:31 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	output_message(char *str, t_philis *philo, char *colour)
{
	u_int64_t	actual_time;

	pthread_mutex_lock(&philo->data->write);
	if (philo->data->write_check == 0)
	{
		actual_time = get_time(philo->data) - philo->start_time;
		printf("%llu %d %s%s%s\n", actual_time, philo->id, colour, str, X);
	}
	pthread_mutex_unlock(&philo->data->write);
}

void	life_circle(t_philis *philo)
{
	pthread_mutex_lock(philo->left_fork);
	output_message(TAKE_FORK, philo, YELLOW);
	pthread_mutex_lock(philo->right_fork);
	output_message(TAKE_FORK, philo, YELLOW);
	output_message(EATING, philo, GREEN);
	ft_usleep(philo->data->eat_time, philo);
	pthread_mutex_lock(&philo->finished);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->finished);
	pthread_mutex_lock(&philo->kill_check);
	philo->kill_time = get_time(philo->data) + philo->data->death_time;
	pthread_mutex_unlock(&philo->kill_check);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	output_message(SLEEPING, philo, BLUE);
	ft_usleep(philo->data->sleep_time, philo);
	output_message(THINKING, philo, RED);
}
