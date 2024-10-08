/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:20:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/10 18:49:58 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_cycle(t_philosopher *philo, t_data *data)
{
	data_print(philo, "is thinking");
	philosopher_sleeping(data->time_to_sleep, data);
	take_forks(philo, data);
	eat(data, philo);
	sleeping_cycle(philo, data);
	if (false == philo_must_die(philo, data))
	{
		if (0 == is_dead(philo, data))
			return (false);
	}
	return (true);
}
