/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:58:04 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/14 15:22:35 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"




int	thread_create(t_data *data)
{
	pthread_t	death_thread;

	int(i) = -1;
	

	while (++i < data->number_of_philo)
	{
		if (pthread_create(&data->philosophers[i].thread_id, NULL,
				algo_of_dijkstra, &data->philosophers[i]) != 0)
		{
			printf("probleme with pthread_create\n");
			return (false);
		}
	}
	if (pthread_create(&death_thread, NULL, death_checker, (void *)data) != 0)
	{
		printf("Error creating death_checker thread.\n");
		return (false);
	}
	if (pthread_join(death_thread, NULL) != 0)
	{
		printf("Error joining death_checker thread.\n");
		return (false);
	}
	i = -1;
	while (++i < data->number_of_philo)
	{
		if (pthread_join(data->philosophers[i].thread_id, NULL) != 0)
		{
			printf("probleme with  pthread_join  in algo_of_dijkstra\n");
			return (false);
		}
	}
	 destroy_all_mutex(data, i);
	return (true);
}
