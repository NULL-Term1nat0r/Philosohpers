/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputChecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:25:31 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/19 15:26:15 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int error(char *error_msg)
{
	printf("%s\n", error_msg);
	return (1);
}

int	non_digit(char *s)
{
	if (s[0] == '+' && s[1] == '\0')
		return (1);
	if (*s == '+')
		s++;
	while (*s != '\0')
	{
		if (*s < 48 || *s > 57)
			return (1);
		s++;
	}
	return (0);
}

int	check_input(int argc, char **args)
{
	int	i;

	i = 1;
	if (argc < 5)
		return (error("too less arguments"));
	if (argc > 6)
		return (error("too many arguemnts"));
	if (ft_atoi(args[i]) <= 0)
		return (error("invalid number of philosophers"));
	while (args[i])
	{
		if (ft_atoi(args[i]) < 0)
			return (error("invalid numbers, number must be over 0"));
		if (non_digit(args[i]))
			return (error("invalid character"));
		i++;
	}
	return 0;
}

int	get_input(t_data *data, int argc, char **args)
{
	if (check_input(argc, args) == 0)
	{
		data->philo_num = ft_atoi(args[1]);
		data->death_time = ft_atoi(args[2]);
		data->eat_time = ft_atoi(args[3]);
		data->sleep_time = ft_atoi(args[4]);
		if (argc == 6)
			data->meals_num = ft_atoi(args[5]);
		else
			data->meals_num = -1;
		return (0);
	}
	else
		return (1);
}
