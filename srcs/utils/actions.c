/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:04:29 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 05:26:43 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void output_message(char *str, t_philis *philo)
{
	u_int64_t actual_time;

	pthread_mutex_lock(&philo->data->write);
	actual_time = get_time() - philo->start_time;
	// if (ft_strcmp(DYING, str) == 0)
	// {
	// 	printf("%llu %d %s\n", actual_time, philo->id, str);
	// 	ft_exit(philo->data);
	// }
	// if (ft_strcmp(FINISHED, str) == 0)
	// {
	// 	printf("%llu %s\n", actual_time, str);
	// 	ft_exit(philo->data);
	// }
	// else
	printf("%llu %d %s\n", actual_time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

void output_dying(char *str, t_philis *philo)
{
	u_int64_t actual_time;

	pthread_mutex_lock(&philo->data->write);
	actual_time = get_time() - philo->start_time;
	printf("%llu %d %s\n", actual_time, philo->id, str);
	ft_exit(philo->data);
}

void output_finished(char *str, t_philis *philo)
{
	u_int64_t actual_time;

	pthread_mutex_lock(&philo->data->write);
	actual_time = get_time() - philo->start_time;
	printf("%llu %d %s\n", actual_time, philo->id, str);
	ft_exit(philo->data);
}

// void sleeping(t_philis *philo)
// {
// 	output_message(SLEEPING, philo);
// 	ft_usleep(philo->data->sleep_time);
// }

// void drop_forks(t_philis *philo)
// {
// 	pthread_mutex_unlock(philo->right_fork);
// 	pthread_mutex_unlock(philo->left_fork);
// }

// void take_forks(t_philis *philo)
// {
// 	pthread_mutex_lock(philo->left_fork);
// 	output_message(TAKE_FORK, philo);
// 	pthread_mutex_lock(philo->right_fork);
// 	output_message(TAKE_FORK, philo);
// }

void life_circle(t_philis *philo)
{
	// if (philo->data->philo_num % 2 != 0 && philo->id == 1)
	// 	ft_usleep(philo->data->eat_time);
	death_check(philo);
	pthread_mutex_lock(philo->left_fork);
	death_check(philo);
	output_message(TAKE_FORK, philo);
	pthread_mutex_lock(philo->right_fork);
	death_check(philo);
	output_message(TAKE_FORK, philo);
	philo->kill_time = get_time() + philo->data->death_time;
	output_message(EATING, philo);
	ft_usleep(philo->data->eat_time, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	meal_check(philo);
	output_message(SLEEPING, philo);
	ft_usleep(philo->data->sleep_time, philo);
	output_message(THINKING, philo);
}

