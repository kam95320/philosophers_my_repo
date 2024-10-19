/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:33:47 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/19 14:00:01 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	cond_in_if(t_data *data)
{
	printf("%lld %d %s\n", timestamp() - data->first_timestamp,
		data->philosophers->id, "died");
	data->are_you_dead = 1;
	data->limit_simulation = 1;
	data->balise_death = 1;
	pthread_mutex_unlock(&data->protect_dead_var);
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
		while (++i < data->number_of_philo && 0 == data->are_you_dead)
		{
			pthread_mutex_lock(&data->protect_dead_var);
			res = (timestamp() - data->philosophers[i].time_last_meal);
			t_l_m = time_diff(data->philosophers[i].time_last_meal, tim);
			if (t_l_m > data->time_to_death || res > data->time_to_death)
			{
				cond_in_if(data);
				return (NULL);
			}
			pthread_mutex_unlock(&data->protect_dead_var);
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
// void	*death_checker(void *arg)
// {
// 	t_data		*data;
// 	long long	t_l_m;
// 	long long	tim;
// 	long		res;
// 	int			i;

// 	data = (t_data *)arg;
// 	tim = timestamp();
// 	if (data->number_of_meals > 0)
// 		return (NULL);
// 	cond_death(data);
// 	while (!data->limit_simulation)
// 	{
// 		i = -1;
// 		while (++i < data->number_of_philo && 0 == data->are_you_dead)
// 		{
// 			pthread_mutex_lock(&data->protect_dead_var);
// 			res = (timestamp() - data->philosophers[i].time_last_meal);
// 			t_l_m = time_diff(data->philosophers[i].time_last_meal, tim);
// 			cond_death(t_l_m,  res, data);
// 			if (t_l_m > data->time_to_death || res > data->time_to_death)
// 			{
// 				cond_in_if(data);
// 				return (NULL);
// 			}
// 			pthread_mutex_unlock(&data->protect_dead_var);
// 			usleep(100);
// 		}
// 	}
// return (NULL);
// }
