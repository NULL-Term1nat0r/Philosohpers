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

#define TAKE_FORK	"has taken a fork"
#define EATING		"is eating"
#define SLEEPING	"is sleeping"
#define THINKING	"is thinking"
#define DYING 		"died"


struct s_data;


typedef struct s_philis
{
	pthread_t		waiter;
	struct s_data	*data;
	int 			id;
	int				eat_count;
	int 			eat_status;

	uint64_t 		kill_time;
	uint64_t		start_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
} t_philis;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_num;
	int				dead;
	int				finished;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	struct s_philis	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

//	utils
int	ft_atoi(char *argv);
void error(char *error_msg);
void get_input(t_data *data_struct, int argc, char **args);
int	ft_strcmp(char *s1, char *s2);

//	time
u_int64_t	get_time(void);
int	ft_usleep(useconds_t time);

//	init
void init_all_structs(t_data *data, int argc, char **argv);

//	checker

//exit
void	ft_exit(t_data *data);

//	actions
void output_message(char *str, t_philis *philo);
void eating(t_philis *philo);

//	threads
int thread_init(t_data *data);
void catch_threads(t_data *struct_data);

#endif
