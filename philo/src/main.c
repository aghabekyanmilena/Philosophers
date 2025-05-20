/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:19:10 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/20 19:19:12 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*pxik(void *data)
{
	(void)data;
	printf("pxik\n");
	return (NULL);
}

void	create_threads(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->philo_count)
	{
		pthread_create(&table->philo[index].thread, NULL, pxik, NULL);
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
	create_threads(table);
	while (index < table->philo_count)
		pthread_join(table->philo[index++].thread, NULL);
	free_table(table);
	return (0);
}
