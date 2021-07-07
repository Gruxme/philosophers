/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:48:15 by abiari            #+#    #+#             */
/*   Updated: 2021/07/07 15:58:07 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_simulation(t_philos_params **init_data, int i)
{
	if ((get_current_time() - (*init_data)->philos[i].last_meal)
		> (*init_data)->die_time)
	{
		print_status("died", &(*init_data)->philos[i]);
		return (1);
	}
	if ((*init_data)->supervisor_counter == (*init_data)->n_philosophers)
		return (1);
	return (0);
}

int	supervisor(t_philos_params *init_data)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < init_data->n_philosophers)
		{
			if (!init_data->philos[i].is_eating)
			{
				pthread_mutex_lock(&init_data->philos[i].philo_eat);
				if (end_simulation(&init_data, i))
					return (1);
				pthread_mutex_unlock(&init_data->philos[i].philo_eat);
			}
			i++;
		}
		ft_usleep(800);
	}
	return (0);
}
