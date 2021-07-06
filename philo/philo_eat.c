/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:08:17 by abiari            #+#    #+#             */
/*   Updated: 2021/07/05 17:46:40 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->init_data->forks[philo->left_fork]);
	print_status("has taken left fork", philo);
	pthread_mutex_lock(&philo->init_data->forks[philo->right_fork]);
	print_status("has taken right fork", philo);
	pthread_mutex_lock(&philo->philo_eat);
	print_status("is eating", philo);
	philo->is_eating = 1;
	philo->last_meal = get_current_time();
	philo->n_times_ate++;
	if (philo->n_times_ate == philo->init_data->n_times_to_eat)
		philo->init_data->supervisor_counter++;
	ft_usleep(philo->init_data->eat_time * 1000);
	pthread_mutex_unlock(&philo->philo_eat);
	pthread_mutex_unlock(&philo->init_data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->init_data->forks[philo->right_fork]);
	philo->is_eating = 0;
}
