/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:57:24 by abiari            #+#    #+#             */
/*   Updated: 2021/07/09 15:14:40 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philos_params	*init_data;

	if (argc != 5 && argc != 6)
		return (0);
	init_data = (t_philos_params *)malloc(sizeof(t_philos_params));
	if (!fill_init_data(init_data, argc, argv))
		return (0);
	sem_unlink("forks");
	init_data->forks = sem_open("forks", O_CREAT, 0644,
			init_data->n_philosophers);
	sem_unlink("write");
	init_data->write = sem_open("write", O_CREAT, 0644, 1);
	sem_unlink("eating");
	init_data->philo_eat = sem_open("eating", O_CREAT, 0644,
			init_data->n_philosophers / 2);
	threads_init(init_data);
	return (0);
}
