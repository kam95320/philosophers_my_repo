/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:58:04 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/19 18:36:23 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	thread_join(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
		pthread_join(data->philosophers[i].thread_id, NULL);
}

int	thread_create(t_data *data)
{
	pthread_t		death_thread;
	t_philosopher	*philo;
	int				i;

	philo = data->philosophers;
	i = -1;
	data->first_timestamp = timestamp();
	while (++i < data->number_of_philo)
	{
		if (pthread_create(&data->philosophers[i].thread_id, NULL,
				algo_of_dijkstra, &data->philosophers[i]) != 0)
		{
			return (false);
			philo[i].time_last_meal = timestamp();
		}
	}
	if (pthread_create(&death_thread, NULL, death_checker, (void *)data))
		return (false);
	if (pthread_join(death_thread, NULL) != 0)
		return (false);
	thread_join(data);
	destroy_all_mutex(data, i);
	return (true);
}
