/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:57:52 by abiari            #+#    #+#             */
/*   Updated: 2021/07/07 15:02:26 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_philos_params *init_data)
{
	int		i;

	i = -1;
	init_data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* init_data->n_philosophers);
	while (++i < init_data->n_philosophers)
	{
		pthread_mutex_init(&(init_data->forks[i]), NULL);
		init_data->philos[i].last_meal = get_current_time();
	}
	return ;
}

t_philo	*philos_init(t_philos_params *init_data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)malloc(init_data->n_philosophers * sizeof(t_philo));
	while (i < init_data->n_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % init_data->n_philosophers;
		philo[i].n_times_ate = 0;
		pthread_mutex_init(&(philo[i].philo_eat), NULL);
		philo[i].init_data = init_data;
		philo[i].is_eating = 0;
		i++;
	}
	return (philo);
}

void	threads_init(t_philos_params *init_data)
{
	pthread_t	thread_id;
	int			i;

	i = 0;
	init_data->start_time = get_current_time();
	pthread_mutex_init(&(init_data->write), NULL);
	while (i < init_data->n_philosophers)
	{
		pthread_create(&thread_id, NULL, &routine, &init_data->philos[i]);
		i += 2;
	}
	ft_usleep(1000);
	i = 1;
	while (i < init_data->n_philosophers)
	{
		pthread_create(&thread_id, NULL, &routine, &init_data->philos[i]);
		i += 2;
	}
	return ;
}

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	fill_init_data(t_philos_params *init_data, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!check_arg(av[i]))
		{
			printf("error args\n");
			return (0);
		}
		i++;
	}
	init_data->n_philosophers = ft_atoi(av[1]);
	if (init_data->n_philosophers == 0)
		return (0);
	init_data->die_time = ft_atoi(av[2]);
	init_data->eat_time = ft_atoi(av[3]);
	init_data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		init_data->n_times_to_eat = ft_atoi(av[5]);
	else
		init_data->n_times_to_eat = 0;
	init_data->supervisor_counter = 0;
	init_data->philos = philos_init(init_data);
	return (1);
}
