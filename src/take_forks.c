/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:04:05 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/07 15:49:16 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

 void	take_forks(t_philosopher *philo, t_data *data)
{
	// printf("take_forks  begin\n");
	if (philo->left_fork_id < philo->right_fork_id)
	{
	
		
		// printf("take_forks middle in if nb_philo = %d\n", data -> number_of_philo);
		pthread_mutex_lock(&(data->protect_forks_data[philo->left_fork_id]));
		data_print(philo, "has taken a fork");
		// printf("take_forks middle in if 2 nb_philo = %d\n", data -> number_of_philo);
		
		pthread_mutex_lock(&(data->protect_forks_data[philo->right_fork_id]));
		data_print(philo, "has taken a fork");
		//  philo_must_die(philo, data, nb);
	}
	
	else
	{
		// printf("take_forks middle in else\n");
		pthread_mutex_lock(&(data->protect_forks_data[philo->right_fork_id]));
		data_print(philo, "has taken a fork");

		pthread_mutex_lock(&(data->protect_forks_data[philo->left_fork_id]));
		data_print(philo, "has taken a fork");
		// philo_must_die(philo,  data, nb);
	}
	// printf("take_forks  end\n");
	
}