/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:33:47 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/14 16:13:31 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// int just_one(t_data *data, t_philosopher *philo)
// {
// 	if (data->number_of_philo == 1)
// 	{
// 		data_print(philo, "has taken a fork");
// 		// philosopher_sleeping(data->time_to_death, data);
// 		// is_dead(philo, data);
//         return(1);
// 	}
//     return(0);
// }

// void *death_checker(void *arg)
// {

//     t_data *data = (t_data *)arg;
//     int i;
//     //  printf("number_of_philo =  %d\n", data->number_of_philo);

//     while (!data->limit_simulation)
//     {

//         i = -1;
//         while (++i < data->number_of_philo)
//         {
//                 // if( 1 == just_one(data, data -> philosophers))
//                 //         return(NULL);

//             // printf("number_of_philo in  while =  %d\n",
		// data->number_of_philo);
//             // printf("number i  =  %d\n",  i);
// 			pthread_mutex_lock(&data->protect_dead_var);
//             long long time_since_last_meal = time_diff(data->philosophers[i].time_last_meal,
		// timestamp());

//             if (time_since_last_meal > data->time_to_death)
//             {
// 				// printf("pass in if cond\n");
//                 printf("%lld %d %s\n", timestamp() - data->first_timestamp,
// 						data ->philosophers->id, "died");
//                 data->are_you_dead = 1;
//                 data->limit_simulation = 1;
// 				data ->balise_death = 1;
//            			pthread_mutex_unlock(&data->protect_dead_var);

//                 return (NULL);

//             }
//             pthread_mutex_unlock(&data->protect_dead_var);

//         }
//         usleep(1000);
//     }
// 		printf(" death_checker end\n\n");
//     return (NULL);
// }

void	*death_checker(void *arg)
{
	// printf("death_checker begin\n\n");
	t_data *data = (t_data *)arg;
	int i;

	while (!data->limit_simulation)
	{
		// printf("death_checker begin\n\n");
		// if(1 == data->balise_death)
		// 		return(NULL);

		i = -1;
		while (++i < data->number_of_philo)
		{
			pthread_mutex_lock(&data->protect_dead_var);
			long long time_since_last_meal = time_diff(data->philosophers[i].time_last_meal, timestamp());

			if (time_since_last_meal >= data->time_to_death)
			{
				
					printf("pass in if cond\n");
					printf("%lld %d %s\n", timestamp() - data->first_timestamp,
							data->philosophers->id, "died");
					data->are_you_dead = 1;
					data->limit_simulation = 1;
					data->balise_death = 1;
					pthread_mutex_unlock(&data->protect_dead_var);
					printf("pass in if cond end\n");
					return (NULL);
					printf("pass in if cond end2\n");
				 
			}
			pthread_mutex_unlock(&data->protect_dead_var);
		}
		// usleep(100);
	}
	printf(" death_checker end\n\n");
	return (NULL);
}