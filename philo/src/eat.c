/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:43:37 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/19 17:54:37 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eat(t_data *data, t_philosopher *philo)
{
	pthread_mutex_lock(&(data->protect_meal_data));
	data_print(philo, "is eating");
	philo->time_last_meal = timestamp();
	pthread_mutex_unlock(&(data->protect_meal_data));
	ft_usleep(data->time_to_eat, data);
	(philo->nb_cycle)++;
}
