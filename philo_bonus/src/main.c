/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:50:57 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/03 15:39:26 by miaghabe         ###   ########.fr       */
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
		waitpid(table->philo[i].pid, &status, 0);
		i++;
	}
}

void	end_simulation(t_table *table)
{
	int	i = 0;

	while (i < table->philo_count)
		kill(table->philo[i++].pid, SIGKILL);
}

void	wait_for_finish(t_table *table)
{
	sem_wait(table->dead);
	end_simulation(table);
}

void	*monitor_full(void *arg)
{
	t_table *table = (t_table *)arg;
	int i = 0;

	while (i < table->philo_count)
	{
		sem_wait(table->fullness);
		i++;
	}
	sem_post(table->dead);
	return NULL;
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	if (!validation(argc, argv))
		return (1);
	if (!init_semaphores(&table))
		return (1);
	if (!init_philos(&table))
		return (1);
	table.start_time = get_time_in_ms();
	if (table.num_eats != -1)
		pthread_create(&table.full_eat_thread, NULL, monitor_full, &table);
	i = 0;
	while (i < table.philo_count)
	{
		table.philo[i].pid = fork();
		if (table.philo[i].pid == 0)
			philo_life(&table.philo[i]);
		i++;
	}	
	wait_for_finish(&table);
	free_table(&table);
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	t_table	*table;

// 	if (!validation(argc, argv))
// 		return (1);
// 	table = init_table(argc, argv);
// 	if (!table)
// 		return (1);
// 	if (!create_philosophers(table))
// 	{
// 		free_table(table);
// 		return (1);
// 	}
// 	wait_for_children(table);
// 	free_table(table);
// 	return (0);
// }
