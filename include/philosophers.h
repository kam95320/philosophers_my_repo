/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:12:17 by kahoumou          #+#    #+#             */
/*   Updated: 2024/10/12 14:54:24 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSPHERS_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philosopher
{
	int					id;
	int					nb_cycle;
	int					left_fork_id;
	int					right_fork_id;
	long long			time_last_meal;
	struct s_data		*data;
	pthread_t			thread_id;
}						t_philosopher;

typedef struct s_data
{
	int					number_of_philo;
	int					time_to_death;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;
	int					nb_philo;
	int					are_you_dead;
	int					limit_simulation;
	int					balise_death;
	long long			first_timestamp;
	struct s_variables	*variable;
	pthread_t			death_trhead;
	pthread_mutex_t		protect_meal_data;
	pthread_mutex_t		protect_forks_data[250];
	pthread_mutex_t		protect_writing_data;
	pthread_mutex_t		protect_dead_var;
	pthread_mutex_t		protect_balise_death;
	t_philosopher		philosophers[250];
}						t_data;

int						check_argument(int argc, char *argv[]);
int						convert_digit(char *argv[], t_data *data);
void					print_msg(void);
int						init_mutex(t_data *data);
int						init_philo(t_data *data);
int						thread_create(t_data *data);
void					philosopher_sleeping(long long time, t_data *data);
void					take_forks(t_philosopher *philo, t_data *data);
void					eat(t_data *data, t_philosopher *philo);
void					*algo_of_dijkstra(void *arg);
void					put_forks(t_philosopher *philo, t_data *data);
long long				timestamp(void);
long long				time_diff(long long past, long long pres);
int						ft_isdigit(int character);
int						ft_atoi(char *str);
void					destroy_all_mutex(t_data *data, int nb);
int						ave_you_one_arg(t_philosopher *philo, t_data *data);
void					sleeping_cycle(t_philosopher *philo, t_data *data);
int						philo_cycle(t_philosopher *philo, t_data *data);
int						check_meals(t_data *data, int nb);
int						is_dead(t_philosopher *philo, t_data *data);
int						philo_must_die(t_philosopher *philo, t_data *data);
int						dead_or_not(t_data *data);
void					data_print(t_philosopher *philo, char *str);
void					*death_checker(void *arg);
#endif