/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:08:24 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/01 19:09:27 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_philosophers(t_table *table)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < table->philo_count)
	{
		pid = fork();
		if (pid < 0)
			return (error_handling(FORK_ERROR), 0);
		if (pid == 0)
		{
			philosopher_routine(&table->philo[i]);// es functionny chunes poxi
			return (0);
		}
		else
			table->philo[i].pid = pid;
		i++;
	}
	return (1);
}

void	print_action(t_philo *philo, char *msg)
{
	long	time;

	sem_wait(philo->table->print);
	time = get_time_in_ms() - philo->table->start_time;
	printf("%ld %d %s\n", time, philo->index + 1, msg);
	sem_post(philo->table->print);
}
