/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_must_die.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:32:54 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/09 15:47:28 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int philo_must_die(t_philosopher *philo, t_data *data)
{
	
	// printf(" begin of philo_must_die\n");
	if ((timestamp() - philo->time_last_meal) > data->time_to_death)
		return (false);
	
	if (data->time_to_death < (data->time_to_sleep + data->time_to_eat))
		return (false);
	if(data -> number_of_philo  ==  1)
	{
		return(false);
	}
	
	return (true);
}