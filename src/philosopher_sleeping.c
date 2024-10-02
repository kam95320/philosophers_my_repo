/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_sleeping.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:33:12 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/30 14:07:36 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philosopher_sleeping(long long time, t_data *data)
{
	long long	i;

	// printf("begin of philosopher_sleeping philo = %d time ms = %lld\n",
			// philo  -> id, time);
	i = timestamp();
	// printf("philosopher %d is thinking\n" , philo->id);
	while (0 == data->are_you_dead)
	{
		if (time_diff(i, timestamp()) >= time)
		{
			break ;
		}
		usleep(50);
	}
	//  printf("end of philosopher_sleeping philo = %d time ms = %lld\n", philo 
			// -> id, time);
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}
