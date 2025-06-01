/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:37:08 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/01 17:05:07 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_philosophers(t_table *table)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < table->philo_count)
	{
		pid = fork();
		if (pid < 0)
			return (error_handling(FORK_ERROR), 0);
		if (pid == 0)
		{
			philosopher_routine(&table->philo[i]);
			exit(0);
		}
		else
			table->philo[i].pid = pid;
		i++;
	}
	return (1);
}

void	philosopher_routine(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (philo->index % 2 == 0)
		usleep(1000);
	while (1)
	{
		sem_wait(table->secure_fork);
		print_status(philo, "has taken a fork");
		sem_wait(table->secure_fork);
		print_status(philo, "has taken a fork");
		sem_wait(&philo->last_meal_sem);
		philo->last_meal = get_time_in_ms();
		sem_post(&philo->last_meal_sem);
		print_status(philo, "is eating");
		philo_usleep(philo, table->time_to_eat);
		philo->eat_count++;
		if (table->num_eats > 0 && philo->eat_count == table->num_eats)
			sem_post(table->fullness);
		sem_post(table->secure_fork);
		sem_post(table->secure_fork);
		print_status(philo, "is sleeping");
		philo_usleep(philo, table->time_to_sleep);
		print_status(philo, "is thinking");
	}
}

void	print_status(t_philo *philo, char *message)
{
	long	timestamp;

	sem_wait(philo->table->print);
	timestamp = get_time_in_ms() ;
	printf("%ld %d %s\n", timestamp, philo->index, message);
	sem_post(philo->table->print);
}

void	*death_monitor(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	long	time;

	while (1)
	{
		usleep(1000);
		sem_wait(&philo->last_meal_sem);
		time = get_time_in_ms() - philo->last_meal;
		if (time > philo->table->time_to_die)
		{
			sem_post(philo->table->dead);
			print_status(philo, "died");
			return (NULL);
		}
		sem_post(&philo->last_meal_sem);
	}
	return (NULL);
}
