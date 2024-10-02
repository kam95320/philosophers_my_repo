/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_of_dijkstra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:08:33 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/02 15:55:15 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int check_meals(t_data  *data, int nb)
{
	// printf("in cheak_ meals\n\n\n");
	int i;
	i =  nb;
	
	if(data ->  number_of_meals != 0)
	{
		if(i  <= data -> number_of_meals)
		{
			i += 1;
			return(true);
		}
		return(false);
	}
	return(0);
}

void  is_dead(t_philosopher *philo, t_data  *data)
{
	// printf("is_dead pass  begin\n");
	data_print(philo, "died");
	
	pthread_mutex_lock(&data -> protect_dead_var);
	 		 data->are_you_dead = 1;
	pthread_mutex_unlock(&data -> protect_dead_var);
	// printf("is_dead pass end\n");
}

static void	sleep_routine(t_data *data, t_philosopher *philo)
{
	data_print(philo, "is sleeping");
	usleep(data->time_to_sleep * 1000);
}
void	*algo_of_dijkstra(void *arg)
{
	//  printf(" begin  of algo_of_dijkstra\n");
	t_philosopher	*philo;
	t_data			*data;
	int  nb;
	nb =  -1;
	philo = (t_philosopher *)arg;
	data = philo->data;

	if (philo->id % 2)
	{
		usleep(1500);
	}
	while (0 == data->are_you_dead)
	{
		//  printf("begin is inside  while loop  of algo_dijikstra of  philo %d\n",
		//  philo->id);
		 if(data -> number_of_philo ==  1)
		 		is_dead(philo,  data);
				
		if(data  -> number_of_meals > 0)
		{	
			nb += 1;
			if(false == check_meals(data, nb))
			 break;
		}
		
		if (data->are_you_dead != 0)
			break ;
		
		data_print(philo, "is thinking");
		philosopher_sleeping(data->time_to_sleep, data);
		take_forks(philo, data);
		eat(data, philo);
		philosopher_sleeping(data->time_to_eat, data);
		if ((timestamp() - philo->time_last_meal) > data->time_to_death)
		{
			is_dead(philo, data);	
			break ;
		}
		put_forks(philo, data);
		data_print(philo, "is sleeping");
		sleep_routine(data, philo);
		if(data -> time_to_death  < (data -> time_to_sleep  + data->time_to_eat))
		{
			// printf("pass  in  death  condition\n\n");
			is_dead(philo, data);
			return(NULL);		
		}
	}

// printf(" end  of algo_of_dijkstra\n");
return (NULL);
}
