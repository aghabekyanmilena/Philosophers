/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:40:52 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/16 15:36:11 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	check_limits(long long num)
// {
// 	if ((num > INT_MAX || num < INT_MIN))
// 		return (write(2, "Error\n", 6), 0);
// 	return (1);
// }

int	is_number(char *str)
{
	int i = 0;

	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]) || ft_atoi(argv[i]) <= 0)
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}
