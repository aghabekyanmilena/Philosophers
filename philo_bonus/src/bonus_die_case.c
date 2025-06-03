/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_die_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:56:59 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/03 15:22:58 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_death(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(&philo->last_meal_sem);
		if (get_time_in_ms() - philo->last_meal > philo->table->time_to_die)
		{
			sem_post(&philo->last_meal_sem);
			print_action(philo, "is dead");
			sem_post(philo->table->dead);
			// return ;
		}
		sem_post(&philo->last_meal_sem);
		usleep(1000);
	}
	return (NULL);
}

void	philos_full(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		sem_wait(table->fullness);
		i++;
	}
	sem_post(table->dead);
}
