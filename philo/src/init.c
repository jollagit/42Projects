#include "philo.h"

void	init_condition(t_condition *condition, char **argv)
{
	condition->init_time = get_time();
	condition->num_of_philos = ft_atoi(argv[1]);
	condition->time_to_die = (size_t) ft_atoi(argv[2]);
	condition->time_to_eat = (size_t) ft_atoi(argv[3]);
	condition->time_to_sleep = (size_t) ft_atoi(argv[4]);
	if (argv[5])
		condition->num_time_to_eat = ft_atoi(argv[5]);
	else
		condition->num_time_to_eat = 0;
	pthread_mutex_init(&condition->eating_mutex, NULL);
	pthread_mutex_init(&condition->check_death, NULL);
	condition->died = 0;
	condition->ate_all = 0;
	init_fork(condition);
}

void	init_fork(t_condition *condition)
{
	int		i;

	i = 0;
	while (i < condition->num_of_philos)
	{
		condition->fork[i].id = i + 1;
		pthread_mutex_init(&condition->fork[i].mutex, NULL);
		i++;
	}
}

void	init_philo(t_condition *condition)
{
	int		i;

	i = 0;
	while (i < condition->num_of_philos)
	{
		condition->philo[i].id = i + 1;
		condition->philo[i].condition = condition;
		condition->philo[i].last_meal = get_time();
		condition->philo[i].meals_eaten = 0;
		condition->philo[i].left_fork = &condition->fork[i];
		condition->philo[i].right_fork = &condition->fork[(i + 1) % condition->num_of_philos];
		i++;
	}
}

