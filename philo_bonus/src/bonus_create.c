/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:08:24 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/04 18:59:43 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_philosophers(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->philo_count)
	{
		table->pid[i] = fork();
		if (table->pid[i] < 0)
			return (error_handling(FORK_ERROR), 0);
		if (table->pid[i] == 0)
		{
			philo_life(&table->philo[i]);
			exit (0);
		}
		i++;
	}
	return (1);
}

void	print_action(t_philo *philo, char *msg)
{
	long	time;

	sem_wait(philo->table->print);
	time = get_time_in_ms() - philo->table->start_time;
	printf("[%ld] %d %s\n",
		get_time_in_ms() - philo->table->start_time,
		philo->index,
		msg);
	sem_post(philo->table->print);
}
