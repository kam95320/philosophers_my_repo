/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:17:49 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/09 15:49:23 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	data_print(t_philosopher *philo, char *str)
{
	
	// for(int i =  0;  i == 0;  i ++)
	// 	printf("data_print begin pass = %d \n", i);
	
	pthread_mutex_lock(&philo->data->protect_writing_data);
	if (philo->data->balise_death == false)
	{	
		printf("%lld %d %s\n", timestamp() - philo->data->first_timestamp,
				philo -> id,str);
	}
	pthread_mutex_unlock(&philo->data->protect_writing_data);
	// for(int i =  1;  i <= 1;  i ++)
	// printf("data_print end  pass  = %d \n\n", i);
	
}