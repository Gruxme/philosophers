/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:10:23 by abiari            #+#    #+#             */
/*   Updated: 2021/07/09 12:43:59 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(uint64_t sleep_time)
{
	uint64_t	start;
	// uint64_t	time_diff;
	start = get_current_time();
	usleep(sleep_time - 20000);
	while (get_current_time() - start < sleep_time / 1000)
		continue ;
}
