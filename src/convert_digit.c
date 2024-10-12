/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:16:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/12 21:01:32 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	convert_digit(char *argv[], t_data *data)
{
	// pthread_mutex_lock(&data->protect_dead_var);
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_death = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->limit_simulation = 0;
	data->are_you_dead = 0;
	data->balise_death = 0;
	// pthread_mutex_unlock(&data->protect_dead_var);
	if (argv[5] != NULL)
	{
		data->number_of_meals = ft_atoi(argv[5]);
		if (data->number_of_meals <= 0)
			return (1);
	}
	else
		data->number_of_meals = -1;
	if (data->number_of_philo < 0 || data->time_to_death < 0)
	{
		return (false);
	}
	if (data->time_to_eat < 0 || data->time_to_sleep < 0
		|| data->number_of_philo > 250)
	{
		return (false);
	}
	return (true);
}
