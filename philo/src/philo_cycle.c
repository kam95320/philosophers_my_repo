/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:20:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/23 13:49:34 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_cycle(t_philosopher *philo, t_data *data)
{
	if (data->limit_simulation)
		return (false);
	data_print(philo, "is thinking");
	take_forks(philo, data);
	eat(data, philo);
	put_forks(philo, data);
	data_print(philo, "is sleeping");
	ft_usleep(data->time_to_sleep, data);
	return (true);
}
