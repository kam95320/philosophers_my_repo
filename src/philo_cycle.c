/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:20:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/07 19:49:50 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"


int	philo_cycle(t_philosopher *philo, t_data *data)
{
	//  printf("in philo_cycle the begining\n");
	// int	nb;
	// nb = -1;
	data_print(philo, "is thinking");
	philosopher_sleeping(data->time_to_sleep, data);
	take_forks(philo, data);
	eat(data, philo);
	philosopher_sleeping(data->time_to_eat, data);
	if (false == philo_must_die(philo, data))
		return (false);
	 sleeping_cycle(philo, data);
	return (true);
}
