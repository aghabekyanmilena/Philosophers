/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:38:16 by alisharu          #+#    #+#             */
/*   Updated: 2025/05/21 13:33:56 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, const char *str)
{
	pthread_mutex_lock(&philo->table->program_stop_mutex);
	if (!philo->table->program_stop)
	{
		pthread_mutex_unlock(&philo->table->program_stop_mutex);
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("[%ld] %d %s\n",get_time_in_ms()
			- philo->table->start_time, philo->index, str);
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	else
		pthread_mutex_unlock(&philo->table->program_stop_mutex);
}

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	philo_usleep(t_philo *philo, int sleep_time)
{
	long	start;
	long	current;

	start = get_time_in_ms();
	while (1)
	{
		current = get_time_in_ms();
		if (current - start >= sleep_time)
			break ;
		pthread_mutex_lock(&philo->table->program_stop_mutex);
		if (philo->table->program_stop)
		{
			pthread_mutex_unlock(&philo->table->program_stop_mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->table->program_stop_mutex);
		usleep(100);
	}
}
