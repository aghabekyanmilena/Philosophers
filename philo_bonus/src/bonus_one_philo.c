/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_one_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:59:30 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/01 18:56:35 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	one_philo(t_philo *philo)
{
	t_table *table;

	table = philo->table;
	sem_wait(table->secure_fork);
	print_status(philo, "has taken a fork");
	philo_usleep(philo, table->time_to_die);
	print_status(philo, "died");
	sem_post(table->dead);
}
