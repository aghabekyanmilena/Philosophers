/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:42:54 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/20 14:49:45 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_values(t_table *data)
{
	int	i;

	// data->init_philo = 0; 
	data->philo = malloc(sizeof(pthread_t *) * (data->philo_nbr));
	if (!data->philo)
		return (-1);
	pthread_mutex_init(&data->mutex, NULL); // chgitem esi incha petqa uxel
	pthread_mutex_init(&data->mutex, NULL); // sa el
	pthread_mutex_init(&data->forks, NULL); // sa el
	data->philo = malloc(sizeof(t_philo) * data->philo_nbr);
	if (!data->philo)
		return (-1);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	if (!data->mutex)
		return (-1);
	i = -1;
	while (++i < data->philo_nbr)
	{
		data->num_eats = 0;
		data->philo[i].right_fork = i - 1;
		data->philo[i].left_fork = i;
	}
	data->philo[0].right_fork = data->philo_nbr - 1;
	return (0);
}
