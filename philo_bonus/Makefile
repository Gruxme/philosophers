# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiari <abiari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/03 12:59:14 by abiari            #+#    #+#              #
#    Updated: 2021/07/09 11:57:02 by abiari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = philo.c time_funcs.c ft_atoi.c inits.c ft_isdigit.c philo_eat.c\
print_status.c philo_sleep.c philo_think.c supervisor.c ft_strcmp.c\
ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c


all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re
