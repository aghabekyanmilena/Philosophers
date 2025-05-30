/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:09:42 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/31 20:57:28 by miaghabe         ###   ########.fr       */
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
# include <pthread.h>
# include <semaphore.h>

# define INVALID_ARGUMENT 1
# define INVALID_SYMBOLS 2
# define INVALID_PHILO_COUNT 3
# define INVALID_NUMBER 4
# define CALLOC_ERROR 5

typedef struct s_table t_table;
typedef struct s_philo t_philo;

struct s_table
{
	long			philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_eats;
	long			full_eat;
	sem_t			start_time;
	sem_t			print;
	sem_t			fullness;
	sem_t			dead;
	sem_t			secure_fork;
	pthread_t		is_dead_thread;
	pthread_t		full_eat_thread;
	t_philo			*philo;
};

typedef struct s_philo
{
	int				index;
	int				eat_count;
	long long		last_meal;
	sem_t			last_meal_sem;
	pthread_t		thread;
	t_table			*table;
	pid_t			*pid;
}	t_philo;

// usleep
void	philo_usleep(t_philo *philo, int sleep_time);

// utils
void	error_handling(int num);
long	ft_atol(const char *str);
void	*ft_calloc(size_t count, size_t size);
long	get_time_in_ms(void);

// validation
int	validate_arguments(int argc, char **argv);
int	validation(int argc, char **argv);

#endif