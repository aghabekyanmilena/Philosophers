/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:10 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/22 18:49:23 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		pthread_mutex_lock(&philo->table->program_stop_mutex);
		if (philo->table->program_stop)
			return (pthread_mutex_unlock(&philo->table->program_stop_mutex),
				NULL);
		pthread_mutex_unlock(&philo->table->program_stop_mutex);
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	create_threads(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->philo_count)
	{
		pthread_create(&table->philo[index].thread, NULL,
			life, &table->philo[index]);

		index++;
	}
}

int	main(int argc, char **argv)
{
	t_table	*table;
	int		index;

	index = 0;
	if (validation(argc, argv) == 0)
		return (0);
	table = init_table(argc, argv);
	table->start_time = get_time_in_ms();
	create_threads(table);
	pthread_create(&table->is_dead_thread, NULL, check_dead, table);
	if (argc == 6)
		pthread_create(&table->full_eat_thread, NULL, check_full_eat, table);
	pthread_join(table->is_dead_thread, NULL);
	if (argc == 6)
		pthread_join(table->full_eat_thread, NULL);
	while (index < table->philo_count)
		pthread_join(table->philo[index++].thread, NULL);
	free_table(table);
	return (0);
}
