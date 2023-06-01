#include "../../includes/philo.h"

void *manager(void *data)
{
	t_philis *philo;

	philo = (t_philis *) data;
	pthread_mutex_lock(&philo->data->lock);
	while (philo->data->dead == 0)
	{
		pthread_mutex_unlock(&philo->data->lock);
		pthread_mutex_lock(&philo->data->lock);
		if (philo->data->finished >= philo->data->philo_num)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->lock);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return ((void *)0);
}

void *waiter(void *data)
{
	t_philis *philo;

	philo = (t_philis *)data;
	pthread_mutex_lock(&philo->data->lock);
	while (philo->data->dead == 0)
	{
		pthread_mutex_unlock(&philo->data->lock);
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->kill_time && philo->eat_status == 0)
			output_message(DYING, philo);
		if (philo->eat_count == philo->data->meals_num)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->eat_count++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_lock(&philo->data->lock);
		pthread_mutex_unlock(&philo->lock);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return ((void *)0);
}

//void *routine(void *philo_struct)
//{
//	t_philis *philo;
//
//	philo = (t_philis *)philo_struct;
//	philo->start_time = get_time();
//	philo->kill_time = get_time() + philo->data->death_time;
//	if (pthread_create(&philo->waiter, 0, &waiter, (void *)philo))
//		return ((void *)1);
//	while (philo->data->dead == 0)
//		eating(philo);
//	if (pthread_join(philo->waiter, NULL))
//		return ((void *)1);
//	return ((void *)0);
//}

void *routine(void *philo_struct)
{
	t_philis *philo;

	philo = (t_philis *)philo_struct;
	philo->start_time = get_time();
	philo->kill_time = get_time() + philo->data->death_time;
	if (pthread_create(&philo->waiter, 0, &waiter, (void *)philo))
		return ((void *)1);
	pthread_mutex_lock(&philo->data->lock);
	while (philo->data->dead == 0)
	{
		pthread_mutex_unlock(&philo->data->lock);
		eating(philo);
		pthread_mutex_lock(&philo->data->lock);
	}
	pthread_mutex_unlock(&philo->data->lock);
	if (pthread_join(philo->waiter, NULL))
		return ((void *)1);
	return ((void *)0);
}

int thread_init(t_data *data)
{
	int i;
	pthread_t manager_thread;

	i = 0;
	if (data->meals_num > 0)
	{
		if (pthread_create(&manager_thread, NULL, &manager, &data->philo[i]))
			return 1;
	}
	while (i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philo[i]))
			return 1;
		usleep(1);
		i++;
	}
	// i = 0;
	// while (i < data->philo_num)
	// {
	// 	if (pthread_join(data->tid[i], NULL))
	// 		return (1);
	// }
	return (0);
}

void catch_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(data->tid[i], NULL);
		// printf("thread %d has finished execution\n", i);
		i++;
	}
}
