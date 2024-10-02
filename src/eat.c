/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:43:37 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/30 12:52:14 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"


void  eat(t_data  *data, t_philosopher  *philo)
{
    // printf("begin of eat philo =  %d\n", philo -> id);
    pthread_mutex_lock(&(data -> protect_meal_data));
    data_print(philo,  "is eating");
    philo -> time_last_meal =  timestamp();
    pthread_mutex_unlock(&(data -> protect_meal_data));
    usleep(data->time_to_eat);
    (philo -> nb_cycle) ++;
    // printf("end of eat  philo nb = %d\n", philo -> id);
}