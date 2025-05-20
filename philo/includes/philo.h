/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:34 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/19 18:23:00 by miaghabe         ###   ########.fr       */
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

typedef struct s_fork t_fork;
typedef struct s_philo t_philo;
typedef struct s_table t_table;

struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
};

struct s_philo
{
	int			id;
	long		count;
	bool		is_full;
	long		last_meal;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
};

struct s_table
{
	long	philo_nbr;
	long	time_die;
	long	time_eat;
	long	time_sleep;
	long	num_eats;
	long	start_time; // simulation
	bool	end_time; // philo dies or philos full
	t_fork	*forks; //forkeri array
	t_philo	*philo; // philoneri array
	pthread_mutex_t	*mutex;
};

// utils
void	print_error(void);
long	get_time_in_ms(void);

// parsing
void	parse_arguments(t_table *table, char **argv);



#endif