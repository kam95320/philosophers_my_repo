/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:46:33 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/10 18:50:28 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_mutex_pt2(t_data *data, int i)
{
	if (pthread_mutex_init(&(data->protect_writing_data), NULL) != 0)
	{
		printf("errror  with mutex  init  of protect_writing_data =  %d\n", i);
		return (false);
	}
	if (pthread_mutex_init(&(data->protect_meal_data), NULL) != 0)
	{
		printf("errror  with mutex  init  of  protect_meal_data =  %d\n", i);
		return (false);
	}
	if (pthread_mutex_init(&(data->protect_dead_var), NULL) != 0)
	{
		printf("errror  with mutex  init  of protect_dead_var  =  %d\n", i);
		return (false);
	}
	return (1);
}

int	init_mutex(t_data *data)
{
	int	j;
	int	i;

	i = data->number_of_philo;
	j = 1;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->protect_forks_data[i]), NULL) != 0)
		{
			printf("errror  with mutex  init = %d\n", i);
			return (false);
		}
		j++;
	}
	init_mutex_pt2(data, i);
	return (true);
}
