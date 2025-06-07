/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:49:28 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/07 14:45:49 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	eat(t_philo *philo)
{
	sem_wait(philo->last_meal_sem);
	philo->last_meal = get_time_in_ms();
	sem_post(philo->last_meal_sem);
	print_action(philo, "is eating");
	philo_usleep(philo->table->time_to_eat);
	philo->eat_count++;
}

void	*philo_life(void *arg)
{
	t_philo		*philo;
	pthread_t	death_thread;

	philo = (t_philo *)arg;
	pthread_create(&death_thread, NULL, check_philo_die, philo);
	if (philo->table->philo_count == 1)
		return (one_philo_pick_fork(philo), NULL);
	if (philo->index % 2 == 0)
		usleep(1000);
	while (1)
	{
		pick_fork(philo);
		eat(philo);
		if (philo->table->num_eats > 0
			&& philo->eat_count >= philo->table->num_eats)
			sem_post(philo->table->fullness);
		put_fork(philo);
		print_action(philo, "is sleeping");
		philo_usleep(philo->table->time_to_sleep);
		print_action(philo, "is thinking");
	}
	return (NULL);
}
