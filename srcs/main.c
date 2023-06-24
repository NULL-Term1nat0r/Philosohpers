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
		if (thread_init(&data) != data.philo_num + 3)
		{
			printf("thread_creation failed\n");
			return (0);
		}
		pthread_mutex_lock(&data.dead);
		while (data.dead_check == 0)
		{
			pthread_mutex_unlock(&data.dead);
			usleep(200);
		}
		pthread_mutex_unlock(&data.dead);
	}
	if (ft_atoi(argv[1]) != 1)
		ft_exit(&data, data.philo_num);
	return (0);
}
