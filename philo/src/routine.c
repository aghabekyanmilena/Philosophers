/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:52:41 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/24 16:53:49 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, const char *str)
{
	pthread_mutex_lock(&philo->table->program_stop_mutex);
	usleep(50);
	if (philo->table->program_stop)
	{
		pthread_mutex_unlock(&philo->table->program_stop_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->table->program_stop_mutex);
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("[%ld] %d %s\n",
		get_time_in_ms() - philo->table->start_time,
		philo->index,
		str);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

int	philo_should_stop(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(&philo->table->program_stop_mutex);
	stop = philo->table->program_stop;
	pthread_mutex_unlock(&philo->table->program_stop_mutex);
	return (stop);
}

void	*life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		pthread_mutex_lock(&philo->table->program_stop_mutex);
		if (philo->table->program_stop)
			return (pthread_mutex_unlock(&philo->table->program_stop_mutex),
				NULL);
		pthread_mutex_unlock(&philo->table->program_stop_mutex);
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	create_threads(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->philo_count)
	{
		pthread_create(&table->philo[index].thread, NULL,
			life, &table->philo[index]);
		index++;
	}
}
