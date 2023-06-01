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
	else
		data_struct->meals_num = 1000000;
}
