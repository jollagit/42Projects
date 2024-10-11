#include "philo.h"

size_t	get_time()
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int		check_death(t_condition *condition)
{
	pthread_mutex_lock(&condition->check_death);
	if (condition->died != 0)
	{
		pthread_mutex_unlock(&condition->check_death);
		return (1);
	}
	else if (condition->ate_all == condition->num_of_philos)
	{
		pthread_mutex_unlock(&condition->check_death);
		return (1);
	}
	pthread_mutex_unlock(&condition->check_death);
	return (0);
}

int		ft_atoi(const char *str)
{
	int base;
	int sign;

	sign = 1;
	base = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		printf("Input not valid");
		return (0);
	}
	while (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		base = base * 10 + (*str - '0');
		str++;
	}
	return (base * sign);
}
