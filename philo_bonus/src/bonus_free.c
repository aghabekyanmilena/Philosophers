/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:26:03 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/03 16:31:54 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_table(t_table *table)
{
	if (!table)
		return;
	if (table->print)
		sem_close(table->print);
	if (table->dead)
		sem_close(table->dead);
	if (table->fullness)
		sem_close(table->fullness);
	if (table->secure_fork)
		sem_close(table->secure_fork);
	sem_unlink("/print");
	sem_unlink("/dead");
	sem_unlink("/fullness");
	sem_unlink("/forks");
	if (table->philo)
		free(table->philo);
	free(table);
}
