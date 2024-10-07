/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_must_die.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:32:54 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/07 19:17:49 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_must_die(t_philosopher *philo, t_data *data)
{
	
	// printf(" begin of philo_must_die\n");
	if ((timestamp() - philo->time_last_meal) > data->time_to_death)
	{
		// printf("end of philo_must_die\n");
		is_dead(philo, data);
		// destroy_all_mutex(data, nb);
		return (false);
	}
	if (data->time_to_death < (data->time_to_sleep + data->time_to_eat))
	{
		is_dead(philo, data);
		return (false);
	}
	return (true);
}