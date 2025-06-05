/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:34 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/05 14:58:06 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

# define INVALID_ARGUMENT 1
# define INVALID_SYMBOLS 2
# define INVALID_PHILO_COUNT 3
# define INVALID_NUMBER 4
# define CALLOC_ERROR 5

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

struct s_table
{
	long			philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_eats;
	long			full_eat;
	long			start_time;
	long			program_stop;
	pthread_t		is_dead_thread;
	pthread_t		full_eat_thread;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	program_stop_mutex;
	pthread_mutex_t	num_eats_mutex;
	pthread_mutex_t	last_eat_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philo;
};

typedef struct s_philo
{
	int				index;
	int				eat_count;
	long long		last_meal;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	t_table			*table;
}	t_philo;

// validation
int		validation(int argc, char **argv);
int		validate_arguments(int argc, char **argv);

// init
int		init_philo(t_table *table);
t_table	*init_table(int argc, char **argv);
int		init_mutexes(t_table *table);

//free
void	free_table(t_table *table);
void	free_philo(t_table *table);

// utils
void	*ft_calloc(size_t count, size_t size);
long	ft_atol(const char *str);
void	error_handling(int num);
long	get_time_in_ms(void);

// actions
void	create_threads(t_table *table);
void	print_action(t_philo *philo, const char *str);
void	eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	think(t_philo *philo);
void	pick_fork(t_philo *philo);
void	put_fork(t_philo *philo);
void	philo_usleep(t_philo *philo, int sleep_time);
int		philo_should_stop(t_philo *philo);

// checking
void	*check_dead(void *data);
void	*check_full_eat(void *data);

// one philo
int		handle_one_philo(t_table *table);

// routine
void	*life(void *data);

#endif