/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:18:19 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/02 15:53:56 by kahoumou         ###   ########.fr       */
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
// int	main_pt2(t_data *data, char *argv[])
// {
// 	if (0 == convert_digit(argv, data))
// 	{
// 		return (2);
// 	}
// 	if (false == init_mutex(data))
// 	{
// 		return (3);
// 	}
// 	if (false == init_philo(data))
// 	{
// 		return (4);
// 	}
// 	retrn(0);
// }

void debug_convert_digit(t_data  data)
{
	printf("%d\n%d\n%d\n%d\n%d\n", data.number_of_philo, data.time_to_death,
			data.time_to_eat, data.time_to_sleep, data.number_of_meals);
}

int	main(int argc, char *argv[])
{
	//  printf("begin of main\n");
	t_data	data;
	// t_philosopher philo;


		// printf("if  main cond  begin\n");
	if (argc != 5 && argc != 6)
	{
		print_msg();
		return (1);
	}
	if (false == check_argument(argc, argv))
		return (printf("error syntaxe in argument please  write digit\n"), 5);
	if (0 == convert_digit(argv, &data))
		return (2);
		
			// debug_convert_digit(data);
	
	if (false == init_mutex(&data))
		return (3);
	
	if (false == init_philo(&data))
		return (4);
			// printf("if  main cond  end\n");
		
	// printf("number = %d\n", data.number_of_meals);
	if (0 == thread_create(&data))
		return (printf("There was an  error creating  the threads"), 0);
		//  printf("end of main\n");
	return (0);
}
