/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:04:05 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/30 12:55:53 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_forks(t_philosopher *philo, t_data *data)
{
	// printf("begin of take_forks philo nb  =  %d \n",  philo -> id);
	if (philo->left_fork_id < philo->right_fork_id)
	{
		pthread_mutex_lock(&(data->protect_forks_data[philo->left_fork_id]));
		data_print(philo, "has taken a fork");

		pthread_mutex_lock(&(data->protect_forks_data[philo->right_fork_id]));
		data_print(philo, "has taken a fork");
	}
	
	else
	{
		pthread_mutex_lock(&(data->protect_forks_data[philo->right_fork_id]));
		data_print(philo, "has taken a fork");

		pthread_mutex_lock(&(data->protect_forks_data[philo->left_fork_id]));
		data_print(philo, "has taken a fork");
	}
	// printf("end of take_forks philo  nb =  %d \n", philo ->id);
}