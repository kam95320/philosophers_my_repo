/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_of_dijkstra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:08:33 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/19 18:25:56 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*algo_of_dijkstra_pt2(t_philosopher *philo, t_data *data, int nb)
{
	(void)nb;
	while (true == dead_or_not(data))
	{
		if (false == dead_or_not(data))
			break ;
		if (data->are_you_dead)
			break ;
		if (data->balise_death)
			break ;
		if (data->limit_simulation)
			break ;
		if (data->number_of_meals > 0)
		{
			nb += 1;
			if (false == check_meals(data, nb))
				break ;
		}
		if (false == philo_cycle(philo, philo->data))
		{
			break ;
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
		return (0);
	}
	if (philo->id % 2)
	{
		usleep(15000);
	}
	algo_of_dijkstra_pt2(philo, data, nb);
	return (NULL);
}
