/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:29:58 by abiari            #+#    #+#             */
/*   Updated: 2021/07/09 13:58:44 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *msg, t_philo *philo)
{
	uint64_t	time_diff;

	sem_wait(philo->init_data->write);
	time_diff = (get_current_time() - philo->init_data->start_time);
	ft_putnbr_fd(time_diff, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
	if (ft_strcmp(msg, "died") != 0)
		sem_post(philo->init_data->write);
}
