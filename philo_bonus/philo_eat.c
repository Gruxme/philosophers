/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:08:17 by abiari            #+#    #+#             */
/*   Updated: 2021/07/09 13:57:06 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->init_data->forks);
	philo->count++;
	print_status("has taken left fork", philo);
	sem_wait(philo->init_data->forks);
	philo->count++;
	print_status("has taken right fork", philo);
	sem_wait(philo->init_data->philo_eat);
	print_status("is eating", philo);
	philo->is_eating = 1;
	sem_post(philo->init_data->supervisor_counter);
	philo->last_meal = get_current_time();
	ft_usleep(philo->init_data->eat_time * 1000);
	philo->is_eating = 0;
	sem_post(philo->init_data->philo_eat);
	sem_post(philo->init_data->forks);
	philo->count--;
	sem_post(philo->init_data->forks);
	philo->count--;
}
