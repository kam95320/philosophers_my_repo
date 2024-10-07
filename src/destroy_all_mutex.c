/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:46:11 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/07 15:58:01 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void destroy_all_mutex(t_data *data, int nb)
{
	printf("destroy_all_mutex\n");
	while(++nb  < data -> number_of_philo)
				pthread_mutex_destroy(&(data ->protect_forks_data[nb]));
		pthread_mutex_destroy(&(data->protect_writing_data));
}