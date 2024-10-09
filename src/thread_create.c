/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:58:04 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/09 15:49:56 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"


// int thread_create(t_data  *data, t_philosopher  *philo)
// { 
//     // printf("thread_create begin\n");
    
//     int i;
//     (void)philo;
//     i =  -1;
//      data -> first_timestamp  =  timestamp();
//     while(++i < data -> number_of_philo)
//     {
       
//         if(pthread_create(&data->philosophers[i].thread_id, NULL, algo_of_dijkstra, &data->philosophers[i]) != 0)
//         {
//             printf("probleme with pthread_create\n");
//             return(false);
//         }
//     }
//     i = -1;
// 	while (++i <  data->number_of_philo)
// 	{
// 		if(pthread_join(data -> philosophers[i].thread_id, NULL)!=  0)
// 		{
// 			printf("probleme with  pthread_join  in algo_of_dijkstra\n");
//             return(false);
// 		}
//         destroy_all_mutex(data, i);
// 	}
//     // printf("thread_create  end\n");
    

//     return(true); 
// }


int thread_create(t_data  *data)
{
    //  printf(" begening thread_create\n");
    int i;
    i =  0;
    data ->are_you_dead =  0;
     data -> first_timestamp  =  timestamp();
    while(i < data -> number_of_philo)
    {
        
        //  printf("begin is inside  while loop of  thread_create\n");
        if(pthread_create(&data->philosophers[i].thread_id, NULL, algo_of_dijkstra, &data->philosophers[i]) != 0)
        {
            printf("probleme with pthread_create\n");
            return(false);
        }
        // printf("balise_death_value insde while ptrhead =  %d\n", data-> balise_death);
         i ++;
    }
    i = 0;
	while (i <  data->number_of_philo)
	{

		if(pthread_join(data -> philosophers[i].thread_id, NULL)!=  0)
		{
			printf("probleme with  pthread_join  in algo_of_dijkstra\n");
            return(false);
			
		}
        // printf("thread of  philosophe  id =  %p is  execute\n",  (void *)data -> philosophers[i].thread_id);
        // printf("the philosophe nb of philo is =  %d is execute\n",  i);
        i++;
	}
    // printf(" end thread_create\n");
    return(true); 
}