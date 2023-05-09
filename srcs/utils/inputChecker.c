#include "../../includes/philo.h"

void error(char *error_msg)
{
	printf("%s\n", error_msg);
	exit(1);
}

int non_digit(char *s)
{
	while (*s != '\0')
	{
		if (*s < 48 || *s > 57)
			return (1);
		s++;
	}
	return (0);
}
void check_input(int argc, char **args)
{

	int i;

	i = 1;
	if (argc < 5)
		error("too less arguments");
	if (ft_atoi(args[i]) <= 0)
		error("invalid number of philosophers");
	while (args[i])
	{
		if (ft_atoi(args[i]) < 0)
			error("invalid numbers, number must be over 0");
		if (non_digit(args[i]))
			error("invalid character");
		i++;
	}
}
void get_input(t_data *data_struct, int argc, char **args)
{
	check_input(argc, args);
	data_struct->philo_num = ft_atoi(args[1]);
	data_struct->death_time = ft_atoi(args[2]);
	data_struct->eat_time = ft_atoi(args[3]);
	data_struct->sleep_time = ft_atoi(args[4]);
	if (argc == 6)
		data_struct->meals_num = ft_atoi(args[5]);
}

void init_struct(t_data *data_struct, int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	get_input(data_struct, argc, argv);
	data_struct->start_time = get_time();
	data_struct->dead = 0;
	data_struct->philo_status = malloc(sizeof(int*) * data_struct->philo_num);
	while (i < data_struct->philo_num)
	{
		data_struct->philo_status[i] = malloc(sizeof(int) * 3);
		j = 0;
		while (j < 3)
			data_struct->philo_status[i][j++] = 0;
		i++;
	}
}
