/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_cycle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:41:40 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/10 18:42:58 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	sleep_routine(t_data *data, t_philosopher *philo)
{
	(void)data;
	data_print(philo, "is sleeping");
	usleep(data->time_to_sleep * 1000);
}

void	sleeping_cycle(t_philosopher *philo, t_data *data)
{
	put_forks(philo, data);
	sleep_routine(data, philo);
}
