/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:34:57 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/24 17:00:20 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_death(t_table *table, int index)
{
	pthread_mutex_lock(&table->program_stop_mutex);
	table->program_stop = 1;
	pthread_mutex_unlock(&table->program_stop_mutex);
	pthread_mutex_lock(&table->print_mutex);
	printf("[%ld] %d is dead\n", get_time_in_ms() - table->start_time,
		table->philo[index].index);
	pthread_mutex_unlock(&table->print_mutex);
}

static int	check_philo_death(t_table *table, int index)
{
	long	time_since_meal;

	pthread_mutex_lock(&table->philo[index].last_meal_mutex);
	time_since_meal = get_time_in_ms() - table->philo[index].last_meal;
	pthread_mutex_unlock(&table->philo[index].last_meal_mutex);
	if (time_since_meal > table->time_to_die)
	{
		handle_death(table, index);
		return (1);
	}
	return (0);
}

void	*check_dead(void *data)
{
	t_table	*table;
	int		index;

	table = (t_table *)data;
	while (1)
	{
		if (philo_should_stop(&table->philo[0]))
			return (NULL);
		usleep(50);
		index = 0;
		while (index < table->philo_count)
		{
			if (check_philo_death(table, index))
				return (NULL);
			index++;
		}
	}
	return (NULL);
}

void	*check_full_eat(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (1)
	{
		pthread_mutex_lock(&table->program_stop_mutex);
		if (table->program_stop == 1)
			return (pthread_mutex_unlock(&table->program_stop_mutex), NULL);
		pthread_mutex_unlock(&table->program_stop_mutex);
		usleep(50);
		pthread_mutex_lock(&table->num_eats_mutex);
		if (table->full_eat >= table->philo_count)
		{
			pthread_mutex_unlock(&table->num_eats_mutex);
			pthread_mutex_lock(&table->program_stop_mutex);
			table->program_stop = 1;
			pthread_mutex_unlock(&table->program_stop_mutex);
			pthread_mutex_lock(&table->print_mutex);
			printf("[%ld] Dinner is over\n", get_time_in_ms()
				- table->start_time);
			return (pthread_mutex_unlock(&table->print_mutex), NULL);
		}
		pthread_mutex_unlock(&table->num_eats_mutex);
	}
	return (NULL);
}
