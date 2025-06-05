/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:50:57 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/05 14:29:48 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	free_table(table);
	return (0);
}
