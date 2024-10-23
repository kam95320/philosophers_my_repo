/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:33:47 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/23 16:14:08 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	cond_in_if(t_data *data)
{
	pthread_mutex_lock(&data->mutex.protect_writing_data);
	printf("%lld %d died\n", timestamp() - data->first_timestamp,
		data->philosophers->id);
	data->balise_death = 1;
	pthread_mutex_unlock(&data->mutex.protect_writing_data);
}

void	*cond_death(t_data *data)
{
	long long int	t_l_m;
	long long		tim;
	long			res;
	int				i;

	tim = timestamp();
	while (!data->limit_simulation)
	{
		i = -1;
		while (++i < data->number_of_philo && data->are_you_dead == 0)
		{
			pthread_mutex_lock(&data->mutex.protect_meal_data);
			res = (timestamp() - data->philosophers[i].time_last_meal);
			t_l_m = time_diff(data->philosophers[i].time_last_meal, tim);
			pthread_mutex_unlock(&data->mutex.protect_meal_data);
			if (t_l_m >= data->time_to_death || res > data->time_to_death)
			{
				cond_in_if(data);
				return (NULL);
			}
			usleep(100);
		}
	}
	return (NULL);
}

void	*death_checker(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (data->number_of_meals > 0)
		return (NULL);
	cond_death(data);
	return (NULL);
}
