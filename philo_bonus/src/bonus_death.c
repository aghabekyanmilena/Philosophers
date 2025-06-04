/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:55:52 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/04 20:52:37 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	create_threads(t_table *table)
// {
// 	pthread_create(&table->is_dead_thread, NULL, death_monitor, table);
// 	// if (table->num_eats > 0)
// 	// 	pthread_create(&table->full_eat_thread	, NULL, philo_full_eat, table);
// 	pthread_join(table->is_dead_thread, NULL);
// 	// if (table->num_eats > 0)
// 	// 	pthread_join(table->full_eat_thread, NULL);
// }

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


void	*check_philo_die(void	*data)
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
			sem_post(philo->table->dead);
			print_action(philo, "is dead");
			return (NULL);
		}
		sem_post(philo->last_meal_sem);
	}
	return (NULL);
}

// void	*philo_full_eat(void *data)
// {
// 	t_table	*table;
// 	int		count;

// 	table = (t_table *)data;
// 	count = 0;
// 	while (1)
// 	{
// 		sem_wait(table->fullness);
// 		sem_wait(table->all_dead);
// 		if (table->all_dead)
// 			return (sem_post(table->all_dead), NULL);
// 		sem_post(table->all_dead);
// 		if (++count == table->philo_count)
// 		{
// 			sem_wait(table->print);
// 			printf("[%ld] Dinner is over\n",
// 				get_time_in_ms() - table->start_time);
// 			sem_post(table->dead);
// 			return (NULL);
// 		}
// 	}
// 	return (NULL);
// }

void	*philo_full_eat(void *data)
{
	t_table	*table = (t_table *)data;
	int		count = 0;

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
