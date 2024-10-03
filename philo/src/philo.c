#include "philo.h"

// implementa funzione check philo, condizione di fine simulazione ..

static int	eating(t_philo *philo)
{
	t_condition	*condition;

	condition = philo->condition;
	if (check_death(condition) == 1)
		return (1);
	pthread_mutex_lock(&philo->left_fork->mutex);
	if (check_death(condition) == 1)
	{
		pthread_mutex_unlock(&philo->left_fork->mutex);
		return (1);
	}
	printf("%ldms philo %d has taken a fork \n", get_time() - condition->init_time, philo->id);
	if (condition->num_of_philos != 1)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		printf("%ldms philo %d is eating \n", get_time() - condition->init_time, philo->id);
		pthread_mutex_lock(&condition->eating_mutex);
		philo->last_meal = get_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&condition->eating_mutex);
		usleep(condition->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->left_fork->mutex);
	}
	pthread_mutex_unlock(&philo->right_fork->mutex);
	return (0);
}

static void	*routine(void *args)
{
	int				i;
	t_philo			*philo;
	t_condition		*condition;

	i = 0;
	philo = (t_philo *)args;
	condition = philo->condition;
	while (1)
	{
		if (check_death(condition) == 1)
			return (NULL);
		printf("%ldms philo %d is thinking \n", get_time() - condition->init_time, philo->id);
		if (check_death(condition) == 1)
			return (NULL);
		if (eating(philo) == 1)
			return (NULL);
		if (check_death(condition) == 1)
			return (NULL);
		printf("%ldms philo %d is sleeping \n", get_time() - condition->init_time, philo->id);
		if (check_death(condition) == 1)
			return (NULL);
		usleep(condition->time_to_sleep * 1000);
		i++;
	}
	return (NULL);
}

static void	*simulation_check(void *args)
{
	int			i;
	t_condition	*condition;

	condition = (t_condition *)args;
	while (1)
	{
		i = 0;
		while (i < condition->num_of_philos)
		{
			if ((get_time() - condition->philo[i].last_meal) > condition->time_to_die)
			{
				condition->died++;
				printf("%ldms philo %d has died \n", get_time() - condition->init_time, condition->philo[i].id);
				return (NULL);
			}
			i++;
		}
		usleep(1);
	}
}

static void	simulation(t_condition *condition)
{
	int			i;
	int			j;
	pthread_t	monitor_thread;

	i = 0;
	j = 0;
	while (i < condition->num_of_philos)
	{
		pthread_create(&condition->philo[i].thread, NULL, &routine, &condition->philo[i]);
		usleep(1);
		i++;
	}
	pthread_create(&monitor_thread, NULL, &simulation_check, condition);
	while (j < condition->num_of_philos)
	{
		pthread_join(condition->philo[j].thread, NULL);
		j++;
	}
	pthread_join(monitor_thread, NULL);
}

int	main(int argc, char *argv[])
{
	t_condition	condition;

	if (argc < 5)
		return (0);
	init_condition(&condition, argv);
	init_fork(&condition);
	init_philo(&condition);
	simulation(&condition);
	return (0);
}


