/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:49:04 by abiari            #+#    #+#             */
/*   Updated: 2021/07/06 09:41:38 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# define ALIVE	9001
# define DEAD	0

typedef struct s_philos_params	t_philos_params;
typedef struct s_philo			t_philo;

struct s_philo
{
	int					id;
	int					left_fork;
	int					right_fork;
	int					n_times_ate;
	int					is_eating;

	uint64_t			last_meal;

	pthread_mutex_t		philo_eat;
	pthread_t			thread_id;
	t_philos_params		*init_data;
};

struct s_philos_params
{
	int				n_philosophers;
	uint64_t		die_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	int				n_times_to_eat;
	int				is_alive;

	int				supervisor_counter;

	uint64_t		start_time;

	pthread_mutex_t	write;
	pthread_mutex_t	*forks;

	t_philo			*philos;
};

uint64_t	get_current_time(void);
void		ft_usleep(int sleep_time);
int			ft_atoi(const char *ptr);
void		mutex_init(t_philos_params *init_data);
t_philo		*philos_init(t_philos_params *init_data);
void		threads_init(t_philos_params *init_data);
void		fill_init_data(t_philos_params *init_data, int ac, char **av);
void		*routine(void *arg);
int			ft_strcmp(const char *s1, const char *s2);
void		print_status(char *msg, t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philosopher);
void		philo_think(t_philo *philosopher);
void		clear_all(t_philos_params *init_data, void (*del)(void *));
int			supervisor(t_philos_params *init_data);
void		ft_putnbr(uint64_t n);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);

#endif