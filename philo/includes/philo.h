/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:34 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/06 19:51:26 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_table t_table;
typedef struct s_philo t_philo;

struct s_philo
{
	int		index;
	int		num_philo;
	int		sleep_time;
	int		eat_time;
	int		die_time;
	t_table	*philo;
};

struct s_table
{
	int		num_philo;
};

#endif