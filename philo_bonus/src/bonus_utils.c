/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:34:12 by miaghabe          #+#    #+#             */
/*   Updated: 2025/06/04 17:05:41 by miaghabe         ###   ########.fr       */
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

static int	count_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		rem;
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	str[len] = '\0';
	while (n)
	{
		rem = n % 10;
		str[len-- -1] = rem + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s1_dup;

	i = 0;
	s1_dup = (char *)malloc(ft_strlen(s1) + 1);
	if (!s1_dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		s1_dup[i] = s1[i];
		i++;
	}
	s1_dup[i] = '\0';
	return ((char *)s1_dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	return (0);
}
