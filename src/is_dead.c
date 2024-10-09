/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:04:35 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/09 15:46:31 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	is_dead(t_philosopher *philo, t_data *data)
{
	// printf("is_dead begining\n");
	data_print(philo, "died");
	pthread_mutex_lock(&data->protect_dead_var);
	data->are_you_dead = 1;
	data -> balise_death  = 1;
	pthread_mutex_unlock(&data->protect_dead_var);
	// printf("value of  balise_death  = %d\n", data -> balise_death);
	// printf("is_dead ending\n");
}