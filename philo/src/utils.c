#include "philo.h"

size_t	get_time()
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void	free_mutex(t_condition *condition)
{
	t_fork *current;
	t_fork	*next;
	t_fork	*first;

	current = condition->fork;
	first = condition->fork;
	do
	{
		next = current->next;
		pthread_mutex_destroy(&current->mutex);
		free(current);
		current = next;
	}
	while (current != first);
	pthread_mutex_destroy(&condition->eating_mutex);
	pthread_mutex_destroy(&condition->check_death);
	free(condition);
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


// int		eat(t_philo *philo, t_condition *condition)
// {
// 	if (condition->num_of_philos != 1)
// 	{
// 		pthread_mutex_lock(&philo->right_fork->mutex);
// 		if (!check_all(condition))
// 		{
// 			pthread_mutex_unlock(&philo->left_fork->mutex);
// 			pthread_mutex_unlock(&philo->right_fork->mutex);
// 			return (0);
// 		}
// 		printf("%ldms philo %d is eating \n", get_time() - condition->init_time, philo->id);
// 		pthread_mutex_lock(&condition->check_death);
// 		philo->last_meal = get_time();
// 		pthread_mutex_unlock(&condition->check_death);
// 		pthread_mutex_lock(&condition->eating_mutex);
// 		philo->meals_eaten++;
// 		pthread_mutex_unlock(&condition->eating_mutex);
// 		usleep(condition->time_to_eat * 1000);
// 		pthread_mutex_unlock(&philo->right_fork->mutex);
// 	}
// 	pthread_mutex_unlock(&philo->left_fork->mutex);
// 	return (1);
// }

