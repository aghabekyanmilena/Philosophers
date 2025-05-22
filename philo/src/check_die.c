/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:34:57 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/22 18:41:44 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_dead(void *data)
{
	t_table	*table;
	int		index;

	table = (t_table *)data;
	while (1)
	{
		index = 0;
		pthread_mutex_lock(&table->program_stop_mutex);
		if (table->program_stop == 1)
			return (pthread_mutex_unlock(&table->program_stop_mutex), NULL);
		pthread_mutex_unlock(&table->program_stop_mutex);
		usleep(100);
		while(index < table->philo_count)
		{
			pthread_mutex_lock(&table->philo[index].last_meal_mutex);
			if (get_time_in_ms() - table->philo[index].last_meal > table->time_to_die)
			{
				pthread_mutex_unlock(&table->philo[index].last_meal_mutex);
				pthread_mutex_lock(&table->program_stop_mutex);
				table->program_stop = 1;
				pthread_mutex_unlock(&table->program_stop_mutex);
				pthread_mutex_lock(&table->print_mutex);
				printf("[%ld] %d is dead",get_time_in_ms() - table->start_time, table->philo->index + 1);
				pthread_mutex_unlock(&table->print_mutex);
				return (NULL);
			}
			else
				pthread_mutex_unlock(&table->philo[index].last_meal_mutex);
			index++;
		}
	}
	return (NULL);
}

void	*check_full_eat(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while(1)
	{
		pthread_mutex_lock(&table->program_stop_mutex);
		if (table->program_stop == 1)
			return (pthread_mutex_unlock(&table->program_stop_mutex), NULL);
		pthread_mutex_unlock(&table->program_stop_mutex);
		usleep(100);
		pthread_mutex_lock(&table->num_eats_mutex);
		if (table->full_eat == table->num_eats)
		{
			pthread_mutex_unlock(&table->num_eats_mutex);
			pthread_mutex_lock(&table->program_stop_mutex);
			table->program_stop = 1;
			pthread_mutex_unlock(&table->program_stop_mutex);
			pthread_mutex_lock(&table->print_mutex);
			printf("[%ld] Dinner is over\n",get_time_in_ms() - table->start_time);
			return (pthread_mutex_unlock(&table->print_mutex), NULL);
		}
		else
			pthread_mutex_unlock(&table->num_eats_mutex);
	}
	return (NULL);
}
