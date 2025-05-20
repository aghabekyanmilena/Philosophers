/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:17:57 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/20 19:51:10 by miaghabe         ###   ########.fr       */
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
		printf("%ld %d %s\n", timestamp, philo->index, msg);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	pick_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		// printf
	}
}
// void	philo_eating(t_philo *philo)
// {
	
// }