/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:21:10 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/24 16:59:34 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_one_philo(t_table *table)
{
	t_philo	*philo;

	philo = &table->philo[0];
	table->start_time = get_time_in_ms();
	print_action(philo, "has taken a fork");
	philo_usleep(philo, table->time_to_die);
	printf("[%ld] %d is dead\n",
		get_time_in_ms() - table->start_time,
		philo->index);
	free_table(table);
	return (1);
}
