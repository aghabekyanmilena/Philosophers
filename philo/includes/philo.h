/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:34 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/20 17:53:26 by alisharu         ###   ########.fr       */
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

typedef struct s_table
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
}	t_table;

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

// utils
int		validation(int argc, char **argv);
int		validate_arguments(int argc, char **argv);
void	*ft_calloc(size_t count, size_t size);
long	ft_atol(const char *str);
void	error_handling(int num);
int		init_philo(t_table *table);
t_table	*init_table(int argc, char **argv);
void	free_table(t_table *table);
void	free_philo(t_table *table);
int		init_mutexes(t_table *table);


////

void	print_error(void);
long	get_time_in_ms(void);

// parsing
void	parse_arguments(t_table *table, char **argv);



#endif