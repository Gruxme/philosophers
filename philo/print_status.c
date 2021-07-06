/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:29:58 by abiari            #+#    #+#             */
/*   Updated: 2021/07/06 11:04:28 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *msg, t_philo *philo)
{
	uint64_t	time_diff;

	pthread_mutex_lock(&(philo->init_data->write));
	time_diff = (get_current_time() - philo->init_data->start_time);
	printf("%llu %d %s\n", time_diff, philo->id, msg);
	if (ft_strcmp(msg, "died") != 0)
		pthread_mutex_unlock(&(philo->init_data->write));
}
