/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:43:37 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/20 21:01:15 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eat(t_data *data, t_philosopher *philo)
{
	pthread_mutex_lock(&(data->mutex.protect_meal_data));
	data_print(philo, "is eating");
	philo->time_last_meal = timestamp();
	pthread_mutex_unlock(&(data->mutex.protect_meal_data));
	ft_usleep(data->time_to_eat, data);
	(philo->nb_cycle)++;
}
