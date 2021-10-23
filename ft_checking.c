/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:04:08 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/14 14:19:24 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_check(int argc, char **argv, t_envr *myinfo)
{
	if (myinfo == NULL)
		return (ft_put_error("Error", "Imposible inicializar", -1));
	if ((argc < 5 || argc > 6))
		return (ft_put_error("Error", "Numero de parámetros incorrecto", -2));
	
//comprobar que los philos son positivos.
	myinfo->n_philos = ft_atoi(argv[1]);
	myinfo->t_die = ft_atoi(argv[2]);
	myinfo->t_eat = ft_atoi(argv[3]);
	myinfo->t_sleep = ft_atoi(argv[4]);
	if (!myinfo->n_philos || !myinfo->t_die
		|| !myinfo->t_eat || !myinfo->t_sleep)
		return (ft_put_error("Error", "Formato argumentos incorrecto", -3));
	if (argc == 6)
	{
	// comprobar que el numero de comidas es positivo.
		myinfo->lim_meat = ft_atoi (argv[5]);
		if (!myinfo->lim_meat)
			return (ft_put_error("Error", "Número de comidas incorrecto", -4));
	}
	else
		myinfo->lim_meat = -1;
	return (1);
}
