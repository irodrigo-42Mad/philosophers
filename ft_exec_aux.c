/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:47:46 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/11 11:46:18 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_take_fork(int type, t_philo *my_philo)
{
	if (type == 1)
	{
		pthread_mutex_lock(my_philo->left);
		ft_write_phil_st(TAKE_FORK, my_philo);
		pthread_mutex_lock(my_philo->right);
		ft_write_phil_st(TAKE_FORK, my_philo);
	}
	else
	{
		pthread_mutex_lock(my_philo->right);
		ft_write_phil_st(TAKE_FORK, my_philo);
		pthread_mutex_lock(my_philo->left);
		ft_write_phil_st(TAKE_FORK, my_philo);
	}
}

void	ft_check_meals(t_philo *my_philo)
{
	pthread_mutex_lock((my_philo->my_env)->mt_state);
	if (my_philo->meal_num == my_philo->my_env->lim_meat)
	{
		my_philo->my_env->nphil_dead++;
		my_philo->meal_num++;
	}
	pthread_mutex_unlock((my_philo->my_env)->mt_state);
}
