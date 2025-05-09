/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:10 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/09 17:48:40 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int mails = 1;
// void	*fuk()
// {
// 	for (int i = 0; i < 10000000; i++)
// 		mails++;
// 	printf("%d\n", mails);
// }

// int main(void)
// {
// 	pthread_t t;
// 	pthread_create(&t, NULL, &fuk, NULL);
// 	// pthread_create(&a, NULL, &fuk, NULL);
// 	pthread_join(t, NULL);
// 	// pthread_join(a, NULL);
// 	return 0;
// }

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		print_error();
	if (argc != 5 && argc != 6)
	{
		write(1, "Wrong number of arguments\n", 27);
		return (0);
	}
	while (i != argc)
	{
		check_arguments();
		i++;
	}


	
	return (0);
}