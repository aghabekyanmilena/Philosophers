/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:50:57 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/04 19:52:22 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_for_children(t_table *table)
{
	int	i;
	int	status;

	i = 0;
	while (i < table->philo_count)
	{
		waitpid(table->pid[i], &status, 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!validation(argc, argv))
		return (1);
	table = init_table(argc, argv);
	table->start_time = get_time_in_ms();
	if (!table)
		return (1);
	if (table->philo_count == 1)
		return (one_philo_pick_fork(&table->philo[0]), free_table(table), 0);
	if (!create_philosophers(table))
	{
		free_table(table);
		return (1);
	}
	create_threads(table);
	wait_for_children(table);
	free_table(table);
	return (0);
}
