/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_or_not.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:29:37 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/20 21:00:59 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	dead_or_not(t_data *data)
{
	pthread_mutex_lock(&data->mutex.protect_dead_var);
	if (1 == data->are_you_dead)
	{
		pthread_mutex_unlock(&data->mutex.protect_dead_var);
		return (false);
	}
	pthread_mutex_unlock(&data->mutex.protect_dead_var);
	return (true);
}
