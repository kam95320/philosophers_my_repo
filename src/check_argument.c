/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:40:00 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/10 14:18:07 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_argument(int argc, char *argv[])
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (0 == ft_isdigit(argv[j][i]))
			{
				return (false);
			}
			i++;
		}
		j++;
	}
	return (true);
}
