/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:43:37 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/14 16:04:29 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// void	eat(t_data *data, t_philosopher *philo)
// {
// 	pthread_mutex_lock(&(data->protect_meal_data));
// 	data_print(philo, "is eating");
// 	(philo->nb_cycle)++;
// 	philo->time_last_meal = timestamp();
// 	pthread_mutex_unlock(&(data->protect_meal_data));
// 	// usleep(data->time_to_eat * 1000);
// 	 usleep(data->time_to_eat);
	
// }


void eat(t_data *data, t_philosopher *philo)
{
    pthread_mutex_lock(&(data->protect_meal_data));

    // Enregistre le moment où le philosophe commence à manger
    philo->time_last_meal = timestamp();
    philo->nb_cycle++;

    // Affiche le message indiquant que le philosophe est en train de manger
    data_print(philo, "is eating");

    pthread_mutex_unlock(&(data->protect_meal_data));

    // Simule le temps nécessaire pour manger
    usleep(data->time_to_eat * 1000);
}
