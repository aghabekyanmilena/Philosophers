/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:37:08 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/07 14:46:11 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pick_fork(t_philo *philo)
{
	sem_wait(philo->table->forks);
	print_action(philo, "has taken a fork");
	sem_wait(philo->table->forks);
	print_action(philo, "has taken a fork");
}

void	put_fork(t_philo *philo)
{
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
	sem_post(philo->table->deadlock_protect);
}

void	one_philo_pick_fork(t_philo *philo)
{
	sem_wait(philo->table->secure_fork);
	print_action(philo, "has taken a fork");
	philo_usleep(philo->table->time_to_die + 1);
	print_action(philo, "is dead");
	sem_post(philo->table->dead);
	sem_post(philo->table->secure_fork);
	return ;
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
		usleep(1000);
	}
}
