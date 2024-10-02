/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:56:18 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/02 15:50:31 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"


void  debug_init_philo(t_data  *data, int i)
{
	 printf("data->philosophers[i].id =  %d \n", data->philosophers[i].id);
		printf("philo.nb_cycle =  %d \n", data->philosophers[i].nb_cycle);
		printf("philo.left_fork_id = %d\n",	data->philosophers[i].left_fork_id);
		printf("philosophers.right_fork_id = %d\n", data->philosophers[i].right_fork_id);
		printf("philo.time_last_meal =  %lld\n",data->philosophers[i].time_last_meal);
		printf("data->philosophers[i].data = %lld\n", data->philosophers[i].time_last_meal);
		printf("data->philosophers[i].data = %p\n\n\n", (void *)data->philosophers[i].data);
}
int	init_philo(t_data *data)
{
	// printf("begin init_philo\n");
	int i;
	i = data->number_of_philo;

	while (--i >= 0)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].nb_cycle = 0;
		data->philosophers[i].left_fork_id = i;
		data->philosophers[i].right_fork_id = (i + 1) % data->number_of_philo;
		data->philosophers[i].time_last_meal = 0;
		data->philosophers[i].data =  data;
		// debug_init_philo(data, i);
		// printf("end of init_philo\n");
	}

	return (true);
}