/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:28:34 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/05 14:57:56 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->program_stop_mutex);
	if (philo->table->program_stop)
	{
		pthread_mutex_unlock(&philo->table->program_stop_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->table->program_stop_mutex);
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
}

void	put_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	eat(t_philo *philo)
{
	pick_fork(philo);
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	philo_usleep(philo, philo->table->time_to_eat);
	put_fork(philo);
	pthread_mutex_lock(&philo->table->num_eats_mutex);
	philo->eat_count++;
	if (philo->eat_count == philo->table->num_eats)
	{
		philo->table->full_eat++;
		pthread_mutex_unlock(&philo->table->num_eats_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->table->num_eats_mutex);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->program_stop_mutex);
	if (philo->table->program_stop)
	{
		pthread_mutex_unlock(&philo->table->program_stop_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->table->program_stop_mutex);
	if (philo_should_stop(philo))
		return ;
	print_action(philo, "is sleeping");
	philo_usleep(philo, philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->program_stop_mutex);
	if (philo->table->program_stop)
	{
		pthread_mutex_unlock(&philo->table->program_stop_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->table->program_stop_mutex);
	if (philo_should_stop(philo))
		return ;
	print_action(philo, "is thinking");
}
