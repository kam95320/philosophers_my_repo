/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:58:04 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/12 21:05:40 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	thread_create(t_data *data)
{
	pthread_t	death_thread;

	int(i) = -1;
	// data->are_you_dead = 0;
	// data->first_timestamp = timestamp();
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
	//  death_checker(data, data->philosophers);
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

// int	thread_create(t_data *data)
// {
// 	int			i;
// 	pthread_t	death_thread;

// 	i = -1;
// 	data->are_you_dead = 0;
// 	data->first_timestamp = timestamp();
// 	while (++i < data->number_of_philo)
// 	{
// 		if (pthread_create(&data->philosophers[i].thread_id, NULL,
// 				algo_of_dijkstra, &data->philosophers[i]) != 0)
// 		{
// 			printf("Problème avec la création du thread du philosophe %d.\n",
// 					i);
// 			return (false);
// 		}
// 	}
// 	if (pthread_create(&death_thread, NULL, death_checker, (void *)data))
// 	{
// 		printf("Problème avec la création du thread du philosophe %d.\n",
// 				i);
// 		return (false);
// 	}
// 	i = -1;
// 	while (++i < data->number_of_philo)
// 	{
// 		if (pthread_join(data->philosophers[i].thread_id, NULL) != 0)
// 		{
// 			printf("Problème avec pthread_join pour le philosophe %d.\n", i);
// 			return (false);
// 		}
// 	}
// 	if (pthread_join(death_thread, NULL))
// 	{
// 		printf("Problème avec pthread_join pour le philosophe %d.\n", i);
// 		return (false);
// 	}
// 	destroy_all_mutex(data, data->number_of_philo);
// 	return (true);
// }
