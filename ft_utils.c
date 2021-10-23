/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:29:36 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/11 14:32:44 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_atoi(const char *str)
{
	int	nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (*str)
		return (0);
	return (nb);
}

long int	ft_nb_size(long int n)
{
	long int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i *= 10;
	}
	return (i);
}

/*void	ft_itoa_write(unsigned long long n)
{
	long int	size;
	char		pos;

	size = ft_nb_size(n);
	while (size > 0)
	{
		pos = n / size + '0';
		write (1, &pos, 1);
		n = n % size;
		size /= 10;
	}
}*/

void	ft_write_phil_st(int work, t_philo *my_philo)
{
	int	num;

	num = (my_philo->my_env)->lim_meat;
	if (work == END)
	{
		printf ("%s %d", EAT01, num);
		ft_rounds(num);
	}
	else
	{
		printf ("[%lu] ", (my_gettime() - (my_philo->my_env)->init_time));
		printf ("%s%d", GEN01, my_philo->pos + 1);
		if (work == TAKE_FORK)
			printf ("%s", FORK01);
		if (work == EAT)
			printf ("%s", EAT01);
		if (work == SLEEP)
			printf ("%s", SLEEP01);
		if (work == THINK)
			printf ("%s", THINK01);
		if (work == DEAD)
			printf ("%s", DIED01);
	}				
}

void	ft_rounds(int num)
{
	if (num == 1)
		printf ("%s", GEN02);
	else
		printf ("%s", GEN03);
}
