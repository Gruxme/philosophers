# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiari <abiari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/03 12:59:14 by abiari            #+#    #+#              #
#    Updated: 2021/07/07 16:15:21 by abiari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
NAME_BONUS = philo_bonus

SRC = philo.c time_funcs.c ft_atoi.c inits.c ft_isdigit.c philo_eat.c\
print_status.c philo_sleep.c philo_think.c supervisor.c ft_strcmp.c\

SRC_BONUS = philo_bonus.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRC_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME_BONUS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME_BONUS)

re : fclean all

.PHONY: clean fclean all re
