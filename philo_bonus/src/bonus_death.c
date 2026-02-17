/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:55:52 by miaghabe          #+#    #+#             */
/*   Updated: 2026/02/17 19:33:15 by miaghabe         ###   ########.fr       */
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
	{
		kill(table->pid[i++], SIGKILL);
		sem_post(table->fullness);
	}
	return (NULL);
}

void	*check_philo_die(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		usleep(1000);
		sem_wait(philo->last_meal_sem);
		if (get_time_in_ms() - philo->last_meal > philo->table->time_to_die)
		{
			sem_post(philo->last_meal_sem);
			print_action(philo, "is dead");
			sem_post(philo->table->dead);
			exit(DEAD);
		}
		sem_post(philo->last_meal_sem);
	}
	return (NULL);
}

// void *philo_full_eat(void *data)
// {
// 	t_table	*table = (t_table *)data;
// 	int		count = 0;

// 	while (count < table->philo_count)
// 	{
// 		sem_wait(table->fullness);
// 		if (table->philo && table->philo->eat_count >= table->num_eats)
// 			table->full_eat = 1;
// 		count++;
// 		sem_post(table->fullness);
// 	}
// 	sem_wait(table->print);
// 	printf("[%ld] Dinner is over\n", 
// 		get_time_in_ms() - table->start_time);
// 	sem_post(table->dead);
// 	return (NULL);
// }

void *philo_full_eat(void *data)
{
    t_table *table = (t_table *)data;
    int count = 0;

    while (count < table->philo_count)
    {
        sem_wait(table->fullness);
        count++;
		sem_post(table->fullness);
    }

    sem_wait(table->print);
    printf("[%ld] Dinner is over\n",
        get_time_in_ms() - table->start_time);
    sem_post(table->dead);

    return NULL;
}
