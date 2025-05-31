/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:34:12 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/31 20:54:12 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	error_handling(int num)
{
	if (num == 1)
		printf("Error: Invalid argument\n");
	else if (num == 2)
		printf("Error: Invalid symbols\n");
	else if (num == 3)
		printf("Error: Invalid philosopher count\n");
	else if (num == 4)
		printf("Error: Isn't valid number\n");
	else if (num == 5)
		printf("Error: Could't calloc memory\n");
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
