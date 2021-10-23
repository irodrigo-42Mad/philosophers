/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:59:38 by irodrigo          #+#    #+#             */
/*   Updated: 2021/09/24 12:45:41 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_write_error(char *err_tit, char *errmsg)
{
	write(2, "Error\n", 7);
	write(2, "\n", 2);
	write(2, err_tit, ft_strlen(err_tit));
	write(2, errmsg, ft_strlen(errmsg));
}

int	ft_put_error(char *err_tit, char *errmsg, int err_n)
{
	write(2, "Error\n", 7);
	write(2, "\n", 2);
	write(2, err_tit, ft_strlen(err_tit));
	write(2, errmsg, ft_strlen(errmsg));
	return (err_n);
}

int	ft_file_error(int fd)
{
	if (fd == -1)
		exit(ft_put_error(TIT_003, MSG1_003, 0));
	if (fd == -2)
		exit(ft_put_error(TIT_003, MSG1_004, 0));
	return (0);
}
