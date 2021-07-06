/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:08:38 by abiari            #+#    #+#             */
/*   Updated: 2021/07/05 17:38:37 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philosopher)
{
	print_status("is sleeping", philosopher);
	ft_usleep(philosopher->init_data->sleep_time * 1000);
}
