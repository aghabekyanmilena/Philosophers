/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:55:52 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/03 17:58:34 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_philo_die(void	*data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		usleep(100);
		sem_wait(philo->last_meal_sem);
		if (get_time_in_ms() - philo->last_meal > philo->table->time_to_die)
		{
			sem_post(philo->last_meal_sem);
			print_action(philo, "is dead");
			sem_post(philo->table->dead);
			// return (NULL);
		}
		sem_post(philo->last_meal_sem);
	}
	return (NULL);
}