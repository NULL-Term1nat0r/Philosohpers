/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:04:29 by estruckm          #+#    #+#             */
/*   Updated: 2023/05/29 17:11:09 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void output_message(char *str, t_philis *philo)
{
	u_int64_t actual_time;

	pthread_mutex_lock(&philo->data->write);
	actual_time = get_time() - philo->start_time;
	if (ft_strcmp(DYING, str) == 0 && philo->data->dead == 0)
	{
		printf("%llu %d %s\n", actual_time, philo->id, str);
		pthread_mutex_lock(&philo->data->lock);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->lock);
	}
	if (!philo->data->dead)
		printf("%llu philosopher %d %s\n", actual_time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

void sleeping(t_philis *philo)
{
	output_message(SLEEPING, philo);
	ft_usleep(philo->data->sleep_time);
}

void drop_forks(t_philis *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void take_forks(t_philis *philo)
{
	pthread_mutex_lock(philo->left_fork);
	output_message(TAKE_FORK, philo);
	pthread_mutex_lock(philo->right_fork);
	output_message(TAKE_FORK, philo);
}

void eating(t_philis *philo)
{
	if (philo->id % 2 != 0)
		usleep(1000);
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eat_status = 1;
	philo->kill_time = get_time() + philo->data->death_time;
	output_message(EATING, philo);
	philo->eat_count++;
	ft_usleep(philo->data->eat_time);
	philo->eat_status = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
	sleeping(philo);
	output_message(THINKING, philo);
}

