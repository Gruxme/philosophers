/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:48:15 by abiari            #+#    #+#             */
/*   Updated: 2021/07/09 13:58:31 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eat_count(void	*arg)
{
	t_philos_params	*init_data;
	int				total;
	int				i;

	total = 0;
	init_data = (t_philos_params *)arg;
	while (total < init_data->n_times_to_eat)
	{
		i = 0;
		while (i < init_data->n_philosophers)
		{
			sem_wait(init_data->supervisor_counter);
			i++;
		}
		total++;
	}
	sem_wait(init_data->write);
	i = -1;
	while (++i < init_data->n_philosophers)
		kill(init_data->philos[i].pid, SIGKILL);
	return (NULL);
}

void	ft_kill(t_philos_params *init_data)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	while (i < init_data->n_philosophers)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
			break ;
		i++;
	}
	j = -1;
	while (++j < init_data->n_philosophers)
		kill(init_data->philos[j].pid, SIGKILL);
	exit(0);
}

void	*supervisor(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	while (1)
	{
		if (!philos->is_eating)
		{
			if ((get_current_time() - philos->last_meal)
				> philos->init_data->die_time)
			{
				print_status("died", philos);
				exit(1);
			}
		}
		usleep(800);
	}
	return (0);
}
