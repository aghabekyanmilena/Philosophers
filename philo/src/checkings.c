/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:28:41 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/24 15:52:51 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

static int	is_valid_number(char *str)
{
	long	val;
	int		i;
	
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (0);
		str++;
	}
	if (!*str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	val = ft_atol(str);
	if (val < 1 || val > INT_MAX)
		return (0);
	return (1);
}

static int	has_only_valid_chars(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '+' && argv[i][j] != '-')
				return (0);
		}
	}
	return (1);
}

int	validate_arguments(int argc, char **argv)
{
	int		i;
	char	*arg;

	i = 0;
	while (++i < argc)
	{
		arg = argv[i];
		if (!is_valid_number(arg))
			return (error_handling(INVALID_NUMBER), 0);
	}
	return (1);
}

int	validation(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (error_handling(INVALID_ARGUMENT), 0);
	if (!has_only_valid_chars(argc, argv))
		return (error_handling (INVALID_SYMBOLS), 0);
	if (ft_atol(argv[i]) <= 0 || ft_atol(argv[i]) > 500)
		return (error_handling (INVALID_PHILO_COUNT), 0);
	if (!validate_arguments(argc, argv))
		return (0);
	return (1);
}
