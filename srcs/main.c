#include "../includes/philo.h"

void death_check(t_philis *philo)
{
	if (philo->kill_time <= get_time())
		output_dying(DYING, philo);
}

void meal_check(t_philis *philo)
{
	philo->eat_count++;
	if (philo->eat_count == philo->data->meals_num)
	{
		pthread_mutex_lock(&philo->data->meal);
		philo->data->finished++;
		if (philo->data->finished == philo->data->philo_num)
			output_finished(FINISHED, philo);
		pthread_mutex_unlock(&philo->data->meal);
	}
}

int	case_one(t_data *data)
{
	printf("0 1 has taken a fork\n");
	usleep(data->death_time);
	printf("%llu 1 died\n", data->death_time);
	exit(69);
}

int main(int argc, char **argv)
{
	t_data data;

	init_all_structs(&data, argc, argv);
	if (ft_atoi(argv[1]) == 1)
		case_one(&data);
	else
	{
		thread_init(&data);
		while(69)
			usleep(20);
	}
	return 0;
}

