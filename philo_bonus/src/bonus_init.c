/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:08:57 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/31 21:11:25 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (error_handling(CALLOC_ERROR), NULL);
	table->philo_count = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->num_eats = (argc == 6) ? ft_atol(argv[5]) : -1; // sa poxel
	table->full_eat = 0;
	if (init_semaphores(table) == 0) // grel es functian
		return (free_table(table), NULL); // es el
	if (init_philos(table) == 0) // es el
		return (free_table(table), NULL);
	return (table);
}
