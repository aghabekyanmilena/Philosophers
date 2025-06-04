/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:26:03 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/04 20:37:07 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_table(t_table *table)
{
	if (!table)
		return;
	sem_close(table->print);
	sem_close(table->dead);
	sem_close(table->fullness);
	sem_close(table->secure_fork);
	sem_close(table->forks);
	sem_unlink("/print");
	sem_unlink("/dead");
	sem_unlink("/fullness");
	sem_unlink("/forks");
	if (table->philo)
		table->forks = NULL;
	free(table->pid);
	free(table->philo);
	free(table);
}
