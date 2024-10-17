#include "philo.h"

static int	eating(t_philo *philo)
{
	t_condition	*condition;

	condition = philo->condition;
	if (condition->num_of_philos != 1)
	{
		if (!check_all(condition))
			return (0);
		pthread_mutex_lock(&philo->left_fork->mutex); // controlla se effettivamente le forchette di sinistra e destra sono giuste perche i thred si sovrappogono nei lovk delle fork
		printf("%ldms philo %d has taken a fork \n", get_time() - condition->init_time, philo->id);
		if (!check_all(condition))
		{
			pthread_mutex_unlock(&philo->left_fork->mutex);
			return (0);
		}
		pthread_mutex_lock(&philo->right_fork->mutex);
		printf("%ldms philo %d is eating \n", get_time() - condition->init_time, philo->id);

	// if (philo->left_fork < philo->right_fork)
	// {
	// 	pthread_mutex_lock(&philo->left_fork->mutex);
	// 	printf("%ldms philo %d has taken the left fork\n", get_time() - condition->init_time, philo->id);
	// 	pthread_mutex_lock(&philo->right_fork->mutex);
	// 	printf("%ldms philo %d has taken the right fork\n", get_time() - condition->init_time, philo->id);
	// }
	// else
	// {
	// 	pthread_mutex_lock(&philo->right_fork->mutex);
	// 	printf("%ldms philo %d has taken the right fork\n", get_time() - condition->init_time, philo->id);
	// 	pthread_mutex_lock(&philo->left_fork->mutex);
	// 	printf("%ldms philo %d has taken the left fork\n", get_time() - condition->init_time, philo->id);
	// }

		// questo per gestire l'acquisizione delle fork nel caso tu voglia continuare con questa inizializzazione di left e right

		pthread_mutex_lock(&condition->check_death);
		philo->last_meal = get_time();
		pthread_mutex_unlock(&condition->check_death);
		pthread_mutex_lock(&condition->eating_mutex);
		philo->meals_eaten++;
		pthread_mutex_unlock(&condition->eating_mutex);
		usleep(condition->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		pthread_mutex_unlock(&philo->left_fork->mutex);
	}
	return (1);
}

static void	*routine(void *args)
{
	t_philo			*philo;
	t_condition		*condition;

	philo = (t_philo *)args;
	condition = philo->condition;
	while (1)
	{
		if (!check_all(condition))
			return (NULL);
		printf("%ldms philo %d is thinking \n", get_time() - condition->init_time, philo->id);
		if (!eating(philo))
			return (NULL);
		pthread_mutex_lock(&condition->eating_mutex);
		if (condition->num_time_to_eat != 0 && philo->meals_eaten == condition->num_time_to_eat)
			condition->ate_all++;
		pthread_mutex_unlock(&condition->eating_mutex);
		if (!check_all(condition))
			return (NULL);
		printf("%ldms philo %d is sleeping \n", get_time() - condition->init_time, philo->id);
		usleep(condition->time_to_sleep * 1000);
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
			if (!check_death(i, condition))
				return (NULL);
			if (condition->ate_all == condition->num_of_philos)
			{
				printf("%ldms all philosophers have eaten \n", get_time() - condition->init_time);
				return (NULL);
			}
			i++;
		}
		usleep(100);
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
		usleep(100);
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
	t_condition	*condition;

	if (argc < 5)
		return (0);
	condition = malloc (sizeof(t_condition));
	init_condition(condition, argv);
	init_philo(condition);
	simulation(condition);
	free_mutex(condition);
	return (0);
}



