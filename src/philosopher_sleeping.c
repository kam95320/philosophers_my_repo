/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_sleeping.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:33:12 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/12 21:11:43 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philosopher_sleeping(long long time, t_data *data)
{
	long long	i;

	i = timestamp();
    pthread_mutex_lock(&data->protect_dead_var);
	while (0 == data->are_you_dead)
	{
		if (time_diff(i, timestamp()) >= time)
		{
            	pthread_mutex_unlock(&data->protect_dead_var);
			break ;
		}
		usleep(100);
	}
     pthread_mutex_unlock(&data->protect_dead_var);
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

// void philosopher_sleeping(long long time, t_data *data)
// {
//     long long start_time = timestamp();

//     while (timestamp() - start_time < time)
//     {
//         if (data->are_you_dead)
//             return; 
//         usleep(100);
//     }
// }
