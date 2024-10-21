/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_sleeping.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:33:12 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/20 21:02:02 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philosopher_sleeping(long long time, t_data *data)
{
	long long	i;
	int			is_dead;

	i = timestamp();
	pthread_mutex_lock(&data->mutex.protect_dead_var);
	is_dead = data->are_you_dead;
	pthread_mutex_unlock(&data->mutex.protect_dead_var);
	while (!is_dead && time_diff(i, timestamp()) < time)
	{
		pthread_mutex_lock(&data->mutex.protect_dead_var);
		is_dead = data->are_you_dead;
		pthread_mutex_unlock(&data->mutex.protect_dead_var);
	}
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}
