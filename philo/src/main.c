/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:18:19 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/10 15:00:58 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_msg(void)
{
	printf("error  arguments  numbers please enter\n");
	printf("argc 1  = number of philosophers\n");
	printf("argc 2 =  time to die\n");
	printf("argc 3 =  time to eat\n");
	printf("argc 4 =  time to sleep\n");
	printf("argc 5 =  number of times each philosopher must eat\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		print_msg();
		return (1);
	}
	if (false == check_argument(argc, argv))
		return (printf("error syntaxe in argument please  write digit\n"), 5);
	if (0 == convert_digit(argv, &data))
		return (2);
	if (false == init_mutex(&data))
		return (3);
	if (false == init_philo(&data))
		return (4);
	if (0 == thread_create(&data))
		return (printf("There was an  error creating  the threads"), 0);
	return (0);
}
