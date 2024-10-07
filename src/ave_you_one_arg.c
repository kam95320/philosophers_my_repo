/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ave_you_one_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:07:30 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/03 14:08:29 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ave_you_one_arg(t_philosopher *philo, t_data *data)
{
	if (1 == data->number_of_philo)
	{
		is_dead(philo, data);
		return (false);
	}
	return (true);
}