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
	int					id;
	pthread_mutex_t		mutex;
	struct s_fork		*next;
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
void	init_philo(t_condition *condition);
void	free_mutex(t_condition *condition);
int		check_all(t_condition *condition);
t_fork	*init_fork(int nphilo, t_fork *fork);
int		check_death(int i, t_condition *condition);
//int		eat(t_philo *philo, t_condition *condition);
void	init_condition(t_condition *condition, char **argv);

#endif