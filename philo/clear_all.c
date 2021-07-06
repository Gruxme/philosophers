/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:00:11 by abiari            #+#    #+#             */
/*   Updated: 2021/07/06 10:17:54 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_all(t_philos_params *init_data, void (*del)(void *))
{
	int	i;

	i = -1;
	if (init_data != NULL)
	{
		if (init_data->forks)
			(*del)(init_data->forks);
		if (init_data->philos)
			(*del)(init_data->philos);
		free(init_data);
	}
	return ;
}
