/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:57:52 by abiari            #+#    #+#             */
/*   Updated: 2021/07/09 16:18:28 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philos_init(t_philos_params *init_data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)malloc(init_data->n_philosophers * sizeof(t_philo));
	while (i < init_data->n_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].init_data = init_data;
		philo[i].is_eating = 0;
		philo[i].n_times_ate = 0;
		i++;
	}
	return (philo);
}

void	threads_init(t_philos_params *init_data)
{
	int			i;
	pthread_t	p_t;

	i = -1;
	if (init_data->n_times_to_eat > 0)
		pthread_create(&p_t, NULL, &eat_count, (void *)init_data);
	init_data->start_time = get_current_time();
	while (++i < init_data->n_philosophers)
	{
		init_data->philos[i].last_meal = get_current_time();
		init_data->philos[i].pid = fork();
		if (init_data->philos[i].pid < 0)
			exit(1);
		else if (init_data->philos[i].pid == 0)
		{
			pthread_create(&p_t, NULL, &supervisor,
				(void *)(&init_data->philos[i]));
			routine(&init_data->philos[i]);
			exit(1);
		}
		usleep(100);
	}
	ft_kill(init_data);
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

int	check_args(int ac, char **av)
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
	return (1);
}

int	fill_init_data(t_philos_params *init_data, int ac, char **av)
{
	if (!check_args(ac, av))
		return (0);
	init_data->n_philosophers = ft_atoi(av[1]);
	if (init_data->n_philosophers == 0)
		return (0);
	init_data->die_time = ft_atoi(av[2]);
	init_data->eat_time = ft_atoi(av[3]);
	init_data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		init_data->n_times_to_eat = ft_atoi(av[5]);
	else
		init_data->n_times_to_eat = -1;
	if (init_data->n_times_to_eat == 0)
		return (0);
	sem_unlink("counter");
	init_data->supervisor_counter = sem_open("counter", O_CREAT, 0644, 0);
	init_data->philos = philos_init(init_data);
	return (1);
}
