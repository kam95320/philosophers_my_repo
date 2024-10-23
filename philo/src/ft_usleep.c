/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:02:18 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/23 16:19:25 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_usleep(long long time, t_data *data)
{
	long long	i;

	i = timestamp();
	while (!(data->are_you_dead))
	{
		if (time_diff(i, timestamp()) >= time)
			break ;
		usleep(100);
	}
}
