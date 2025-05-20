/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:49:29 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/19 18:23:20 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		print_error();
	if (!is_digit(*str))
		print_error();
	number = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		print_error();
	return (number);
}
static int ft_atoi(char *str)
{
	int	number;

	number = 0;
	str = valid_input(str);
	while (is_digit(*str))
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	if (number > INT_MAX)
		print_error();
	return (number);
}

void	parse_arguments(t_table *table, char **argv)
{
	table->philo_nbr = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->num_eats = ft_atoi(argv[5]);
	else
		table->num_eats = -1;
	table->start_time = get_time_in_ms();
}