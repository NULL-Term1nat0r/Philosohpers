#include "../../includes/philo.h"

void *routine(void *data)
{
	t_philis *philis_struct;
	philis_struct = (t_philis*)data;
	printf("moin\n");
	return NULL;
}

//void thread_routine(t_data *data_struct, int thread_index)
//{
//
//}

void init_struct_philo(t_philis *struct_philis)
{
	int i;

	i = 0;
	struct_philis = malloc(sizeof(*struct_philis) * struct_philis->data->philo_num);
	while (i < struct_philis->data->philo_num)
	{
		struct_philis[i].eat_count = 0;
		struct_philis[i].time_to_die = 0;
		struct_philis[i].status = 0;
		if (pthread_create(&struct_philis->data->tid[i], NULL, &routine, &struct_philis[i]))
			printf("created of thread failed");
		i++;
	}
}