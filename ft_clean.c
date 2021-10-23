/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:43:37 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/12 13:42:10 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

// al final hay que quitar esta función
static void	hola(void)
{
	printf ("\n");
	system("leaks philo");
}

// clean functions
// esta funcion limpia todos los elementos de las estructuras filosofadoras 
// de los filosofistas
void	ft_philos_clean(t_envr *my_envr, t_philo *philos)
{
	int	x;

	x = -1;
	while (my_envr->n_philos < ++x)
		pthread_mutex_destroy(&my_envr->mt_fork_stat[x]);
	pthread_mutex_destroy(my_envr->mt_datamsg);
	pthread_mutex_destroy(my_envr->mt_state);
	pthread_mutex_destroy(my_envr->mt_control);
	free(my_envr->mt_datamsg);
	free(my_envr->mt_control);
	free(my_envr->mt_state);
	free(my_envr->mt_fork_stat);
	free(philos);
	my_envr = NULL;
}

void	ft_total_clean(t_envr *myinfo)
{
	free(myinfo);
	myinfo = NULL;
	atexit(hola);
}
