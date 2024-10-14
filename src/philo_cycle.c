/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:20:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/14 16:14:48 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_cycle(t_philosopher *philo, t_data *data)
{
	if (data->are_you_dead)
        return (false);

	// // pthread_mutex_lock(&data->protect_dead_var);
    // if (data->are_you_dead)
    // {
    //     //  pthread_mutex_unlock(&data->protect_dead_var);
    //     return (false);
    // }
    // // pthread_mutex_unlock(&data->protect_dead_var);
	//  data_print(philo, "is thinking");
	take_forks(philo, data);
	eat(data, philo);
	philosopher_sleeping(data->time_to_sleep, data);
	sleeping_cycle(philo, data);
	return (true);
}




