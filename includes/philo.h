/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:40:52 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/19 22:46:27 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define X "\033[0m"

# define TAKE_FORK	"has taken a fork"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define DYING 		"died"
# define FINISHED	"all philosophers have eaten at least one time"

struct	s_data;

typedef struct s_philis
{
	struct s_data	*data;
	int				id;
	int				eat_count;
	int				finished_eating;
	int				dead_status;
	u_int64_t		kill_time;
	pthread_mutex_t	finished;
	pthread_mutex_t	kill_check;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}	t_philis;

typedef struct s_data
{
	pthread_t		*tid;
	pthread_t 		death_checker;
	pthread_t 		meal_checker;
	int				philo_num;
	int				meals_num;
//	int				finished;
	int 			write_check;
	int				dead_check;
	u_int64_t		start_time;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	struct s_philis	*philo;

	pthread_mutex_t	meal;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	start_signal;
	pthread_mutex_t	dead;
}	t_data;

//	utils
int			ft_atoi(char *argv);
int			get_input(t_data *data_struct, int argc, char **args);
// int	ft_strcmp(char *s1, char *s2);

//	time
u_int64_t	get_time(t_data *data);
int			ft_usleep(useconds_t time, t_philis *philo);

//	init
int			init_all_structs(t_data *data, int argc, char **argv);

//	checker
void		death_check(t_philis *philo);
void		meal_check(t_philis *philo);

int death_check_test(t_philis *philo);

// routine
void		*routine(void *philo_struct);

//exit
void		ft_exit(t_data *data);

//	actions
void		output_error(char *str, t_data *data);
void		output_message(char *str, t_philis *philo, char *colour);
void		output_message_exit(char *str, t_philis *philo);
void	output_message_finished(char *str, t_data *data);
void		life_circle(t_philis *philo);

//	threads
int			thread_init(t_data *data);
void		catch_threads(t_data *struct_data);

#endif
