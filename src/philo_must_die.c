/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_must_die.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:32:54 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/12 14:49:18 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	max_value(int time_to_eat, int time_to_sleep)
{
	if (time_to_eat > time_to_sleep)
		 return (2 * time_to_eat);
		
	return (time_to_eat + time_to_sleep);
}

int	philo_must_die(t_philosopher *philo, t_data *data)
{
	if ((timestamp() - philo->time_last_meal) > data->time_to_death)
		return (false);
	if (data->time_to_death < max_value(data->time_to_eat, data->time_to_sleep))
		return (false);
	if (data->number_of_philo == 1)
	{
		return (false);
	}
	if (philo->data->time_to_eat > philo->data->time_to_death)
	{
		return (false);
	}
	return (true);
}
