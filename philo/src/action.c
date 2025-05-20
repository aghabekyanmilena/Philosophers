/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:28:34 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/20 20:57:08 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, const char *msg)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->print_mutex);
	if (!philo->table->program_stop)
	{
		timestamp = get_time_in_ms() - philo->table->start_time;
		printf("[%ld] %d %s\n", timestamp, philo->index, msg);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_lock(&philo->table->num_eats_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->table->num_eats_mutex);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
}
