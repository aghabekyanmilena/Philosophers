/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:34 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/20 19:51:22 by miaghabe         ###   ########.fr       */
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
	long			start_time;
	int				program_stop;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	num_eats_mutex;
	pthread_mutex_t	start_time_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philo;
};

struct s_philo
{
	int				index;
	int				eat_count;
	long long		last_meal;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	t_table			*table;
};

// validation
int		validation(int argc, char **argv);
int		validate_arguments(int argc, char **argv);

// init
int		init_philo(t_table *table);
t_table	*init_table(int argc, char **argv);
int		init_mutexes(t_table *table);

// free
void	free_table(t_table *table);
void	free_philo(t_table *table);

// utils
void	print_action(t_philo *philo, const char *msg);
void	error_handling(int num);
long	get_time_in_ms(void);
void	*ft_calloc(size_t count, size_t size);
long	ft_atol(const char *str);



#endif