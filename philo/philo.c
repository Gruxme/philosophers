/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:57:24 by abiari            #+#    #+#             */
/*   Updated: 2021/07/07 12:09:14 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_current_time();
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_philos_params	*init_data;

	if (argc != 5 && argc != 6)
		return (255);
	init_data = (t_philos_params *)malloc(sizeof(t_philos_params));
	if (!fill_init_data(init_data, argc, argv))
		return (255);
	mutex_init(init_data);
	threads_init(init_data);
	return (supervisor(init_data));
}
