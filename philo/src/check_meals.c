/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_meals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:02:34 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/18 21:36:22 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_meals(t_data *data, int nb)
{
	int	i;

	i = nb;
	if (data->number_of_meals != 0)
	{
		if (i <= data->number_of_meals)
		{
			i += 1;
			return (true);
		}
		return (false);
	}
	return (false);
}
