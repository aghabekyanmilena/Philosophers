/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:08:57 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/03 19:36:19 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philos(t_table *table)
{
	int	i;

	table->philo = ft_calloc(table->philo_count, sizeof(t_philo));
	if (!table->philo)
		return (error_handling(CALLOC_ERROR), 0);
	i = 0;
	while (i < table->philo_count)
	{
		table->philo[i].index = i + 1;
		table->philo[i].eat_count = 0;
		table->philo[i].last_meal = get_time_in_ms();
		table->philo[i].table = table;
		table->philo[i].pid = 0;
		sem_init(&table->philo[i].last_meal_sem, 1, 1);
		i++;
	}
	return (1);
}

int	init_semaphores(t_table *table)
{
	sem_unlink("/print");
	sem_unlink("/dead");
	sem_unlink("/fullness");
	sem_unlink("/secure_fork");
	sem_unlink("/forks");
	sem_unlink("/deadlock_protect");
	table->forks = sem_open("/forks", O_CREAT, 0644, table->philo_count);
	table->deadlock_protect = sem_open("/deadlock_protect", O_CREAT, 0644, 1);
	if (table->forks == SEM_FAILED || table->deadlock_protect == SEM_FAILED)
		return (error_handling(SEMAPHORE_ERROR), 0);
	table->print = sem_open("/print", O_CREAT, 0644, 1);
	table->dead = sem_open("/dead", O_CREAT, 0644, 0);
	table->fullness = sem_open("/fullness", O_CREAT, 0644, 0);
	table->secure_fork = sem_open("/secure_fork", O_CREAT, 0644, table->philo_count);
	if (table->print == SEM_FAILED || table->dead == SEM_FAILED ||
		table->fullness == SEM_FAILED || table->secure_fork == SEM_FAILED)
		return (error_handling(SEMAPHORE_ERROR), 0);
	return (1);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (error_handling(CALLOC_ERROR), NULL);
	table->philo_count = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		table->num_eats = ft_atol(argv[5]);
	table->full_eat = 0;
	if (init_semaphores(table) == 0)
		return (free_table(table), NULL);
	if (init_philos(table) == 0)
		return (free_table(table), NULL);
	return (table);
}
