/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_of_dijkstra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:08:33 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/12 20:42:41 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*algo_of_dijkstra_pt2(t_philosopher *philo, t_data *data, int nb)
{
	while (1)
	{
		if (false == dead_or_not(data))
			return (NULL);
		if (data->number_of_meals > 0)
		{
			nb += 1;
			if (false == check_meals(data, nb))
				break ;
		}
		// if (data->are_you_dead != 0)
		// 	break ;
		if (false == philo_cycle(philo, data))
		{
			break;
			
		}
	}
	return (NULL);
}

void	*algo_of_dijkstra(void *arg)
{
	t_philosopher	*philo;
	t_data			*data;
	int				nb;

	nb = 0;
	philo = (t_philosopher *)arg;
	data = philo->data;
	if (data->number_of_philo == 1)
	{
		data_print(philo, "has taken a fork");
		philosopher_sleeping(data->time_to_death, data);
		is_dead(philo, data);
		return (0);
	}
	if (philo->id % 2)
	{
		usleep(1500);
	}
	algo_of_dijkstra_pt2(philo, data, nb);
	return (NULL);
}
