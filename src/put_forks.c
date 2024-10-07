/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:48:34 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/02 17:27:47 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	put_forks(t_philosopher *philo, t_data *data)
{
	
	pthread_mutex_unlock(&(data->protect_forks_data[philo->left_fork_id]));
	

	pthread_mutex_unlock(&(data->protect_forks_data[philo->right_fork_id]));
	
}