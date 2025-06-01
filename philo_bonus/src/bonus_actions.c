/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:37:08 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/01 19:09:01 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eating(t_philo *philo)
{
	pick_fork(philo);
	print_action(philo, "is eating");
	sem_wait(&philo->last_meal_sem);
	philo->last_meal = get_time_in_ms();
	sem_post(&philo->last_meal_sem);
	philo_usleep(philo->table->time_to_eat);
	philo->eat_count++;
	if (philo->eat_count == philo->table->num_eats)
		sem_post(philo->table->fullness);
	put_fork(philo);
}

void	philo_sleeping(t_philo *philo)
{
	print_action(philo, "is sleeping");
	philo_usleep(philo->table->time_to_sleep);
}

void	philo_thinking(t_philo *philo)
{
	print_action(philo, "is thinking");
}

void	pick_fork(t_philo *philo)
{
	sem_wait(philo->table->secure_fork);
	print_action(philo, "has taken a fork");
	sem_wait(philo->table->secure_fork);
	print_action(philo, "has taken a fork");
}

void	put_fork(t_philo *philo)
{
	sem_post(philo->table->secure_fork);
	sem_post(philo->table->secure_fork);
}

void	one_philo_pick_fork(t_philo *philo)
{
	sem_wait(philo->table->secure_fork);
	print_action(philo, "has taken a fork");
	philo_usleep(philo->table->time_to_die + 1);
	print_action(philo, "died");
	sem_post(philo->table->dead);
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
