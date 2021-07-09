/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:49:04 by abiari            #+#    #+#             */
/*   Updated: 2021/07/09 13:45:54 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_philos_params	t_philos_params;
typedef struct s_philo			t_philo;

struct s_philo
{
	int					id;
	int					n_times_ate;
	int					is_eating;
	int					count;

	uint64_t			last_meal;
	pid_t				pid;
	t_philos_params		*init_data;
};

struct s_philos_params
{
	int				n_philosophers;
	uint64_t		die_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	int				n_times_to_eat;
	// int				supervisor_counter;
	uint64_t		start_time;

	sem_t			*write;
	sem_t			*forks;
	sem_t			*philo_eat;
	sem_t			*supervisor_counter;

	t_philo			*philos;
};

uint64_t	get_current_time(void);
void		ft_usleep(uint64_t sleep_time);
int			ft_atoi(const char *ptr);
t_philo		*philos_init(t_philos_params *init_data);
void		threads_init(t_philos_params *init_data);
int			fill_init_data(t_philos_params *init_data, int ac, char **av);
void		routine(t_philo *arg);
int			ft_strcmp(const char *s1, const char *s2);
void		print_status(char *msg, t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philosopher);
void		philo_think(t_philo *philosopher);
void		*supervisor(void *philo);
int			ft_isdigit(int s);
void		*eat_count(void	*arg);
void		ft_kill(t_philos_params *init_data);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(uint64_t n, int fd);
void		ft_putstr_fd(char *s, int fd);


#endif
