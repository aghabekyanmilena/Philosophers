/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_one_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:59:30 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/02 14:44:36 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	one_philo(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	sem_wait(table->secure_fork);
	print_status(philo, "has taken a fork");
	philo_usleep(philo);
	print_status(philo, "is dead");
	sem_post(table->dead);
}
