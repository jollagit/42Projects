#include "philo.h"

int		check_all(t_condition *condition)
{
	pthread_mutex_lock(&condition->check_death);
	if (condition->died != 0)
	{
		pthread_mutex_unlock(&condition->check_death);
		return (0);
	}
	pthread_mutex_unlock(&condition->check_death);
	if (condition->num_of_philos != 1)
	{
		pthread_mutex_lock(&condition->eating_mutex);
		if (condition->ate_all == condition->num_of_philos)
		{
			pthread_mutex_unlock(&condition->eating_mutex);
			return (0);
		}
		pthread_mutex_unlock(&condition->eating_mutex);
	}
	return (1);
}

int		check_death(int i, t_condition *condition)
{
	pthread_mutex_lock(&condition->check_death);
	if ((get_time() - condition->philo[i].last_meal) > condition->time_to_die)
	{
		condition->died = 1;
		pthread_mutex_unlock(&condition->check_death);
		printf("%ldms philo %d has died \n", get_time() - condition->init_time, condition->philo[i].id);
		return (0);
	}
	pthread_mutex_unlock(&condition->check_death);
	return (1);
}
