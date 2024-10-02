/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:42:48 by kahoumou          #+#    #+#             */
/*   Updated: 2024/09/26 19:57:09 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((long long)(t.tv_sec) * 1000) + ((long long)(t.tv_usec) / 1000);
}
