#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_data *data_struct;
	t_philis *philis_struct;

	philis_struct = NULL;

	int i;
	int j;

	i = 0;

	data_struct = malloc(sizeof(t_data));
	init_struct(data_struct, argc, argv);
	init_struct_philo(philis_struct);
	printf("time of the day: %llu\n", get_time());
	write(1, "\n", 1);
	while (i < data_struct->philo_num)
	{
		j = 0;
		while (j < 3)
			printf("%d ", data_struct->philo_status[i][j++]);
		printf("\n");
		i++;
	}

	while (i < data_struct->philo_num)
	{

		printf("%d ", philis_struct[i].status);
		i++;
	}
	printf("\n");

	return 0;
}

