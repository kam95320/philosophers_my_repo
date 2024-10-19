# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 18:23:42 by kahoumou          #+#    #+#              #
#    Updated: 2024/10/19 16:01:35 by kahoumou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
#  CFLAGS =  -Werror -Wextra -Wall -g3 -pthread  -fsanitize=thread
#  --tool=helgrind --leak-check=full --show-leak-kinds=all
CFLAGS =  -Werror -Wextra -Wall -g3  
RM = rm -rf

# Liste des sources principales
SRCS =	src/algo_of_dijkstra.c\
		src/check_argument.c\
		src/convert_digit.c\
		src/init_mutex.c\
		src/philosopher_sleeping.c\
		src/put_forks.c\
		src/take_forks.c\
		src/thread_create.c\
		src/timestamp.c\
		src/eat.c\
		src/data_print.c\
		src/main.c\
		src/init_philo.c\
		src/ft_atoi.c\
		src/ft_isdigit.c\
		src/destroy_all_mutex.c\
		src/philo_must_die.c\
		src/check_meals.c\
		src/philo_cycle.c\
		src/dead_or_not.c\
		src/check_death.c\
		src/ft_usleep.c
	
		
		
		

# Cibles pour le projet principal
$(NAME): $(LIBFT) $(SRCS:.c=.o)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# Cibles pour tout compiler
all: $(NAME)

# Nettoyage des fichiers objets et des exécutables
clean:
	$(RM) $(SRCS:.c=.o)

fclean: clean
	$(RM) $(NAME) 

# Reconstruire tout
re: fclean all

