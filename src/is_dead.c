/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:04:35 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/12 19:10:52 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	is_dead(t_philosopher *philo, t_data *data)
{
	long long	cur_time;
	long long	res;

	pthread_mutex_lock(&data->protect_dead_var);
	cur_time = timestamp();
	res = cur_time - philo->data->first_timestamp;
	printf("%lld %d %s\n", res, philo->id, "is died");
	data->are_you_dead = 1;
	data->balise_death = 1;
	pthread_mutex_unlock(&data->protect_dead_var);
	return (false);
}
