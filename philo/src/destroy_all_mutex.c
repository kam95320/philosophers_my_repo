/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:46:11 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/23 16:16:01 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	destroy_all_mutex(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&(data->protect_forks_data[i]));
		i++;
	}
	pthread_mutex_destroy(&data->mutex.protect_meal_data);
	pthread_mutex_destroy(&data->mutex.protect_writing_data);
	pthread_mutex_destroy(&data->mutex.protect_dead_var);
}
