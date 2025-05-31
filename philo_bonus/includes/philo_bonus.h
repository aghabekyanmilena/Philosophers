/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:09:42 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/31 19:30:19 by miaghabe         ###   ########.fr       */
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


#endif