#include "../../includes/philo.h"

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int ft_usleep(useconds_t time)
{
	u_int64_t start;
	u_int64_t elapsed;
	useconds_t remaining;
	start = get_time();
	while (69)
	{
		elapsed = get_time() - start;
		if (elapsed >= time)
			break;
		remaining = time - elapsed;
		usleep(remaining);
	}
	return 0;
}
