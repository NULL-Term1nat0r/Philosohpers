#include "../includes/philo.h"

void death_check(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i].kill_check);
		if (get_time() >= data->philo[i].kill_time)
			output_dying(DYING, &data->philo[i]);
		pthread_mutex_unlock(&data->philo[i].kill_check);
		i++;
	}
}

void meals_finished(t_data *data)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i].finished);
		if (data->philo[i].eat_count == data->meals_num)
			check++;
		pthread_mutex_unlock(&data->philo[i].finished);
		i++;
	}
	if (check == data->philo_num)
		output_finished(FINISHED, &data->philo[i]);
}

void case_one(t_philis *philo)
{
	output_message(TAKE_FORK, philo);
	ft_usleep(philo->data->death_time);
	ft_exit(philo->data);
}

int main(int argc, char **argv)
{
	t_data data;

	init_all_structs(&data, argc, argv);
	thread_init(&data);
	while (69)
	{
		death_check(&data);
		meals_finished(&data);
	}
	return 0;
}

