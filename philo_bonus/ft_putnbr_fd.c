/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:02:55 by abiari            #+#    #+#             */
/*   Updated: 2021/07/09 11:54:55 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr_fd(uint64_t n, int fd)
{
	// if (n < 0)
	// {
	// 	if (n == -2147483648)
	// 	{
	// 		ft_putstr_fd("-2147483648", fd);
	// 		return ;
	// 	}
	// 	n = -n;
	// 	ft_putchar_fd('-', fd);
	// }
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}
