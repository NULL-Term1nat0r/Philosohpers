/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:22:41 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/24 12:55:10 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	case_one(char **argv)
{
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(ft_atoi(argv[4]));
		printf("%d 1 died\n", ft_atoi(argv[4]));
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (case_one(argv) == 1)
		return (0);
	if (init_all_structs(&data, argc, argv) == 1)
		return (0);
	else
	{
		if (thread_init(&data) != 0)
		{
			printf("thread_creation failed\n");
			return (0);
		}
		pthread_mutex_lock(&data.dead);
		while (data.dead_check == 0)
		{
			pthread_mutex_unlock(&data.dead);
			usleep(200);
			pthread_mutex_lock(&data.dead);
		}
		pthread_mutex_unlock(&data.dead);
	}
	if (ft_atoi(argv[1]) != 1)
		ft_exit(&data, data.philo_num + 2);
	return (0);
}
