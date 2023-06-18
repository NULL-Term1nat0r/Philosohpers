#include "../../includes/philo.h"

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int ft_usleep(useconds_t time, t_philis *philo)
{
	u_int64_t wait_time;
	
	wait_time = get_time() + time;
	while (get_time () <= wait_time)
	{
		death_check(philo);
		usleep(200);
	}
	return 0;
}
