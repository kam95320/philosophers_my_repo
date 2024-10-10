/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:17:49 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/10 17:11:08 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	data_print(t_philosopher *philo, char *str)
{
	pthread_mutex_lock(&philo->data->protect_writing_data);
	pthread_mutex_lock(&philo->data->protect_dead_var);
	if (philo->data->balise_death == false)
	{
		printf("%lld %d %s\n", timestamp() - philo->data->first_timestamp,
			philo->id, str);
	}
	pthread_mutex_unlock(&philo->data->protect_dead_var);
	pthread_mutex_unlock(&philo->data->protect_writing_data);
}
