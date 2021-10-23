/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:50:20 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/11 14:04:26 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*ft_life(void *my_philo)
{
	pthread_create(&((t_philo *)my_philo)->state, NULL, ft_ch_phil, my_philo);
	while (TRUE)
	{
		ft_philo_eat((t_philo *)my_philo);
		ft_philo_sleep((t_philo *)my_philo);
		ft_philo_think((t_philo *)my_philo);
	}
	return (NULL);
}

// comprueba como tenemos distribuidos los tenedores dependiendo de par o impar.
// la funcion de impresion no funciona correctamente todavía.
void	*ft_philo_eat(t_philo *my_philo)
{
	if (my_philo->my_env->lim_meat < 0
		|| my_philo->meal_num <= my_philo->my_env->lim_meat)
	{
		if (my_philo->pos % 2)
			ft_take_fork(1, my_philo);
		else
			ft_take_fork(2, my_philo);
		pthread_mutex_lock((my_philo->my_env)->mt_datamsg);
		my_philo->meal_num++;
		my_philo->start = my_gettime();
		ft_write_phil_st(EAT, my_philo);
		pthread_mutex_unlock((my_philo->my_env)->mt_datamsg);
		my_sleep(my_philo->my_env->t_eat);
		pthread_mutex_unlock(my_philo->left);
		pthread_mutex_unlock(my_philo->right);
	}
	return (NULL);
}

void	*ft_philo_sleep(t_philo *my_philo)
{
	pthread_mutex_lock((my_philo->my_env)->mt_datamsg);
	ft_write_phil_st(SLEEP, my_philo);
	pthread_mutex_unlock((my_philo->my_env)->mt_datamsg);
	my_sleep(my_philo->my_env->t_sleep);
	return (NULL);
}

void	*ft_philo_think(t_philo *my_philo)
{
	pthread_mutex_lock((my_philo->my_env)->mt_datamsg);
	ft_write_phil_st(THINK, my_philo);
	pthread_mutex_unlock((my_philo->my_env)->mt_datamsg);
	return (NULL);
}

void	*ft_ch_phil(void *data)
{
	t_philo	*my_philo;

	my_philo = ((t_philo *)data);
	while (TRUE)
	{
		ft_check_meals(my_philo);
		if (my_philo->my_env->nphil_dead == my_philo->my_env->n_philos)
		{
			pthread_mutex_lock((my_philo->my_env)->mt_datamsg);
			ft_write_phil_st(END, my_philo);
			pthread_mutex_unlock((my_philo->my_env)->mt_control);
			return (NULL);
		}
		if ((t_time_ms)(my_gettime() - my_philo->start)
				> (t_time_ms)my_philo->my_env->t_die)
		{
			pthread_mutex_lock((my_philo->my_env)->mt_datamsg);
			ft_write_phil_st(DEAD, my_philo);
			pthread_mutex_unlock((my_philo->my_env)->mt_control);
			return (NULL);
		}
	}
	return (NULL);
}
