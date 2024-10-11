#ifndef PHILO_H
# define PHILO_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/time.h>
#include "pthread.h"


typedef struct  s_philo
{
	pthread_t			thread;
	int					id;
	size_t				last_meal;
	int					meals_eaten;
	struct s_fork		*left_fork;
	struct s_fork		*right_fork;
	struct s_condition	*condition;
}	t_philo;


typedef struct	s_fork
{
	pthread_mutex_t		mutex;
}	t_fork;

typedef struct s_condition
{
	t_philo				philo[200];
	int					num_of_philos;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				init_time;
	int					num_time_to_eat;
	
	pthread_mutex_t		eating_mutex;
	pthread_mutex_t		check_death;
	
	int					died;
	int					ate_all;
	t_fork				*fork;
}	t_condition;


size_t	get_time();
int		ft_atoi(const char *str);
int		check_death(t_condition *condition);
void	check_meals_eaten(void *args);
void	init_philo(t_condition *condition);
void	init_fork(t_condition *condition);
void	init_condition(t_condition *condition, char **argv);

#endif