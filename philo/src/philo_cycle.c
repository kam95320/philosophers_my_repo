/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:20:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/18 21:39:02 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// int	philo_cycle(t_philosopher *philo, t_data *data)
// {
// 	printf("philo_cycle\n");
// 	if(data -> limit_simulation)
// 		return(false);
// 	data_print(philo, "is sleeping");
// 	ft_usleep(data -> time_to_sleep, data);
// 	data_print(philo, "is thinking");
// 	take_forks(philo, data);
// 	eat(data, philo);
// 		// philo->time_last_meal = timestamp();
// 	// sleeping_cycle(philo, data);
// 	put_forks(philo, data);
// 	printf("philo_cycle end\n\n");
// 	return (true);
// }

int	philo_cycle(t_philosopher *philo, t_data *data)
{
	printf("philo_cycle\n");
	// if(data -> limit_simulation)
	// 	return(false);
	data_print(philo, "is sleeping");
	ft_usleep(data->time_to_sleep, data);
	data_print(philo, "is thinking");
	take_forks(philo, data);
	eat(data, philo);
	put_forks(philo, data);
	printf("philo_cycle end\n\n");
	return (true);
}
