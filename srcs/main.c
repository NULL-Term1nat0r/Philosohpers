#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_data data;
	
	init_all_structs(&data, argc, argv);
	thread_init(&data);
	catch_threads(&data);
	ft_exit(&data);
	return 0;
}

