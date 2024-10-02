/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:48:34 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/29 18:36:45 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	put_forks(t_philosopher *philo, t_data *data)
{
	//  printf("begin of put_forks  philo =  %d \n", philo -> id);
	pthread_mutex_unlock(&(data->protect_forks_data[philo->left_fork_id]));
	//  data_print(philo, "has put fork left\n");

	pthread_mutex_unlock(&(data->protect_forks_data[philo->right_fork_id]));
	//  data_print(philo, "has put fork right\n");
	// printf("end of put_forks philo  = %d\n", philo -> id);
}