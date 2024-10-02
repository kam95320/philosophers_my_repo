/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:46:33 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/02 15:50:15 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int init_mutex(t_data  *data)
{
    // printf(" begining of init_mutex\n");
    int (i)  =  data-> number_of_philo;
    int j;
    j = 1;
    
    while(-- i >=  0)
    {
        // printf("inside  init_mutex  boucle while %d\n", j);
        if(pthread_mutex_init(&(data  -> protect_forks_data[i]), NULL) != 0)
        {
            printf("errror  with mutex  init  for protect_forks_data[i]  =  %d\n", i);
            return(false);
        }
        j ++;
    }
        if(pthread_mutex_init(&(data -> protect_writing_data), NULL) != 0)
        {
            printf("errror  with mutex  init  of protect_writing_data =  %d\n", i);
            return(false);
        }
        if(pthread_mutex_init(&(data->protect_meal_data), NULL) !=  0)
        {
            printf("errror  with mutex  init  of  protect_meal_data =  %d\n", i);
            return(false);
        }
        //  printf(" end of  init_mutex\n");
    
    return(true);
}

