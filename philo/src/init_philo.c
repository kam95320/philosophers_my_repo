/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:56:18 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/18 21:38:19 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_philo(t_data *data)
{
	int	i;

	i = data->number_of_philo;
	while (--i >= 0)
	{
		data->first_timestamp = timestamp();
		data->philosophers[i].id = i + 1;
		data->philosophers[i].nb_cycle = 0;
		data->philosophers[i].left_fork_id = i;
		data->philosophers[i].right_fork_id = (i + 1) % data->number_of_philo;
		data->philosophers[i].time_last_meal = data->first_timestamp;
		data->philosophers[i].data = data;
	}
	return (true);
}
