/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:08:01 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/11 14:32:26 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

t_time_ms	my_gettime(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((t_time_ms)(now.tv_sec * 1000 + now.tv_usec / 1000));
}

void	my_sleep(t_time_ms sleep_time)
{
	t_time_ms	stop;

	stop = my_gettime() + sleep_time;
	while (my_gettime() < stop)
		usleep(500);
}
