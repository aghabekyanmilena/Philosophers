/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:55:52 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/05 14:35:45 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_threads(t_table *table)
{
	pthread_create(&table->is_dead_thread, NULL, death_monitor, table);
	if (table->num_eats > 0)
		pthread_create(&table->full_eat_thread, NULL, philo_full_eat, table);
	pthread_join(table->is_dead_thread, NULL);
	if (table->num_eats > 0)
		pthread_join(table->full_eat_thread, NULL);
}

void	*death_monitor(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	sem_wait(table->dead);
	i = 0;
	while (i < table->philo_count)
		kill(table->pid[i++], SIGKILL);
	return (NULL);
}

void	*check_philo_die(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		usleep(100);
		sem_wait(philo->last_meal_sem);
		if (get_time_in_ms() - philo->last_meal > philo->table->time_to_die)
		{
			sem_post(philo->last_meal_sem);
			sem_wait(philo->table->print);
			printf("[%ld] %d is dead\n",
				get_time_in_ms() - philo->table->start_time,
				philo->index);
			sem_post(philo->table->print);
			sem_post(philo->table->dead);
			exit(DEAD);
		}
		sem_post(philo->last_meal_sem);
	}
	return (NULL);
}

void	*philo_full_eat(void *data)
{
	t_table	*table;
	int		count;

	count = 0;
	table = (t_table *)data;
	while (count < table->philo_count)
	{
		sem_wait(table->fullness);
		count++;
	}
	sem_wait(table->print);
	printf("[%ld] Dinner is over\n", get_time_in_ms() - table->start_time);
	sem_post(table->dead);
	return (NULL);
}
