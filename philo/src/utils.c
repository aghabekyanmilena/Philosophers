/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:34:12 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/21 14:20:31 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_handling(int num)
{
	if (num == 1)
		printf("❌ \033[31mError: Invalid argument\e[0m\n");
	else if (num == 2)
		printf("❌ \033[31mError: Invalid symbols\e[0m\n");
	else if (num == 3)
		printf("❌ \033[31mError: Invalid philosopher count\e[0m\n");
	else if (num == 4)
		printf("❌ \033[31mError: Isn't valid number\e[0m\n");
	else if (num == 5)
		printf("❌ \033[31mError: Could't calloc memory\e[0m\n");
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	if ((size != 0 && count > 65536) || (size > 65536 && count != 0))
		return (NULL);
	mem = (unsigned char *)malloc(count * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
