/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:37:08 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/02 14:44:16 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *philo)
{
	pick_fork(philo);
	print_action(philo, "is eating");
	sem_wait(&philo->last_meal_sem);
	philo->last_meal = get_time_in_ms();
	sem_post(&philo->last_meal_sem);
	philo_usleep(philo->table->time_to_eat);
	philo->eat_count++;
	put_fork(philo);// bardracrel em verev
	if (philo->eat_count == philo->table->num_eats)
		sem_post(philo->table->fullness);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	philo_usleep(philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

void	pick_fork(t_philo *philo)
{
	sem_wait(philo->table->secure_fork);//es secure forkery gri fork u menak mi tex wait ara secure fork menak mi philoi depqum
	print_action(philo, "has taken a fork");
	sem_wait(philo->table->secure_fork);
	print_action(philo, "has taken a fork");
}

void	put_fork(t_philo *philo)
{
	sem_post(philo->table->secure_fork);//fork
	sem_post(philo->table->secure_fork);//fork
	sem_post(philo->table->secure_fork);//secure fork
}

void	one_philo_pick_fork(t_philo *philo)
{
	sem_wait(philo->table->secure_fork);
	print_action(philo, "has taken a fork");
	philo_usleep(philo->table->time_to_die + 1);// (time_to_die + 1) * 1000; vor merni
	print_action(philo, "is dead");
	exit(1);
}

void	philo_usleep(int sleep_time)
{
	long	start;
	long	current;

	start = get_time_in_ms();
	while (1)
	{
		current = get_time_in_ms();
		if (current - start >= sleep_time)
			break ;
		usleep(100);
	}
}
