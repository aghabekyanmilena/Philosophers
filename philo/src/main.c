/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:10 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/16 14:12:52 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (write(2, "Error\n", 6), 1);
	if (argc != 5 && argc != 6)
		return(write (2, "Error\n", 6), 1);
	if (!check_args(argc, argv))
		return (1);
	return (0);
}