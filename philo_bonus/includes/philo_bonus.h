/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:09:42 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/03 18:01:02 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
#include <fcntl.h>

# define INVALID_ARGUMENT 1
# define INVALID_SYMBOLS 2
# define INVALID_PHILO_COUNT 3
# define INVALID_NUMBER 4
# define CALLOC_ERROR 5
# define SEMAPHORE_ERROR 6
# define FORK_ERROR 7

typedef struct s_table t_table;
typedef struct s_philo t_philo;

struct s_table
{
	long		philo_count;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		num_eats;
	long		full_eat;
	long		start_time;
	long		program_stop;
	sem_t		*print;
	sem_t		*fullness;
	sem_t		*dead;
	sem_t		*secure_fork; // for one philo
	sem_t		*forks;
	sem_t		*deadlock_protect; // sa nor em avelacrel
	pthread_t	is_dead_thread;
	pthread_t	full_eat_thread;
	t_philo		*philo;
};

// haskanal incha u avelacnel structum ete petqa
//	int			all_dead
//	pid_t		*pid;
//	pthread_t	monitoring_thread;
// sem_t		*all_dead_sem;

struct s_philo
{
	int				index;
	int				eat_count;
	long long		last_meal;
	sem_t			*last_meal_sem;
	pthread_t		thread;
	t_table			*table;
	pid_t			pid;
};

// actions
void	eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	think(t_philo *philo);
void	pick_fork(t_philo *philo);
void	put_fork(t_philo *philo);
void	philo_usleep(int sleep_time);
void	*philo_life(void *arg);

// die case
void	*check_philo_die(void	*data);

// create
int		create_philosophers(t_table *table);

// print
void	print_action(t_philo *philo, char *msg);

// free
void	free_table(t_table *table);

// init
int		init_philos(t_table *table);
int		init_semaphores(t_table *table);
t_table	*init_table(int argc, char **argv);

// one philo
void	one_philo(t_philo *philo);
void	one_philo_pick_fork(t_philo *philo);

// time
long	get_time_in_ms(void);

// checkings
int		validate_arguments(int argc, char **argv);
int		validation(int argc, char **argv);

// utils
void	error_handling(int num);
long	ft_atol(const char *str);
void	*ft_calloc(size_t count, size_t size);


#endif