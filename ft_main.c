/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:04:29 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/12 14:04:10 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_philo.h"

int	main(int argc, char **argv)
{
	t_envr	*my_envr;
	//int		status;

	my_envr = ft_calloc(1, sizeof(t_envr));
	if (ft_check(argc, argv, my_envr) > 0)
	{
		ft_run_threads(my_envr);
		ft_total_clean(my_envr);
		return (0);
	}
	else
		return (-1);
	//status = ft_check(argc, argv, my_envr);


	// la linea que checkea la entrada puede ser la condicion del if
	//y ahorramos una linea y una variable.
	// hasta aqui va PM
	//if (status >= 0)


	// {
	// 	ft_run_threads(my_envr);
	// 	ft_total_clean(my_envr);
	// 	return (0);
	// }
	// else
	// {
	// 	ft_total_clean(my_envr);
	// 	return (-1);
	// }
}

void	*ft_run_threads(t_envr *my_envr)
{
	int		x;
	t_philo	*philos;

	x = 0;
	my_envr->init_time = my_gettime();
	philos = malloc(sizeof(t_philo) * my_envr->n_philos);
	// cuidado con los philosophers y los leaks
	if (!philos)
		return (NULL);
	ft_init_philos(philos, my_envr);
	pthread_mutex_lock(my_envr->mt_control);
	while (my_envr->n_philos > x)
	{
		ft_exec_philo(philos, x, my_envr);
		x++;
	}
	pthread_mutex_lock(my_envr->mt_control);
	ft_philos_clean(my_envr, philos);
	return (NULL);
}
	//usleep(50);

void	ft_init_philos(t_philo *philos, t_envr *my_envr)
{
	int	x;

	my_envr->mt_fork_stat = ft_calloc(my_envr->n_philos,
			sizeof (pthread_mutex_t));
	if (!my_envr->mt_fork_stat)
		return ;
	x = 0;
	while (x < my_envr->n_philos)
	{
		if (x == 0)
			philos[x].left = &my_envr->mt_fork_stat[my_envr->n_philos - 1];
		else
		{
			philos[x].left = &my_envr->mt_fork_stat[x - 1];
		}
		philos[x].right = &my_envr->mt_fork_stat[x];
		pthread_mutex_init(&my_envr->mt_fork_stat[x], NULL);
		x++;
	}
	my_envr->mt_control = ft_calloc(1, sizeof (pthread_mutex_t));
	my_envr->mt_state = ft_calloc(1, sizeof (pthread_mutex_t));
	my_envr->mt_datamsg = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!my_envr->mt_control || !my_envr->mt_state || !my_envr->mt_datamsg)
		return ;
	pthread_mutex_init(my_envr->mt_control, NULL);
	pthread_mutex_init(my_envr->mt_state, NULL);
	pthread_mutex_init(my_envr->mt_datamsg, NULL);
}
