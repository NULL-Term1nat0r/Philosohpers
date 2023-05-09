#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

#define Y "\033[33m"
#define R "\033[31m"
#define G "\033[32m"
#define B "\033[34m"
#define X "\033[0m"

struct s_data;


typedef struct s_philis
{
	pthread_t			thread;
	struct s_data	*data;
	int				eat_count;
	int 			status;
	uint64_t 		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
} t_philis;

typedef struct s_data
{
	pthread_t		*tid;

	int				**philo_status;
	int				philo_num;
	int				meals_num;
	int				dead;
	int				finished;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

//	utils
int	ft_atoi(char *argv);
void error(char *error_msg);
void get_input(t_data *data_struct, int argc, char **args);

//	time
u_int64_t	get_time(void);
int	ft_usleep(useconds_t time);

//	init
void init_struct(t_data *data_struct, int argc, char **argv);
void init_struct_philo(t_philis *struct_philis);

//	checker


//	actions


//	threads

#endif
