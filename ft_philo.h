/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:23:27 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/11 14:32:04 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/stat.h>
# include "./headers/ft_errors.h"
# include "./headers/ft_msg.h"

// de momento para pruebas
# include <string.h>

/*
** Global elements time control
*/
typedef unsigned long	t_time_ms;

/*
** program structures
*/

typedef struct s_envr
{
	pthread_mutex_t	*mt_control;
	pthread_mutex_t	*mt_state;
	pthread_mutex_t	*mt_fork_stat;
	pthread_mutex_t	*mt_datamsg;

	t_time_ms		init_time;

	int				n_philos;
	int				n_forks;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				lim_meat;
	int				nphil_dead;
}	t_envr;

//data for each philosopher
typedef struct s_philo
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

	pthread_t		state;
	pthread_t		primary;
	t_time_ms		start;
	t_envr			*my_env;

	int				pos;
	int				meal_num;
}	t_philo;

/*
** CHARACTER COLOR CONSTANTS
*/
# define YELLOW	"\033[1;33m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define PINK	"\033[1;35m"
# define GRAY	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RED	"\033[1;31m"

/*
** LOGICAL VALUES CONSTANTS
*/
# define TRUE	1
# define FALSE	0

/*
**	PHILO STATUS CONSTANTS   (TRYING IT)
*/
# define TAKE_FORK	1
# define EAT		2
# define SLEEP		3
# define THINK		4
# define DEAD		5
# define END		6

/*
**	check functions
*/
int			ft_check(int argc, char **argv, t_envr *myinfo);

/*
**	Control thread philo functions
*/
void		*ft_run_threads(t_envr *my_envr);
void		ft_init_philos(t_philo *philos, t_envr *my_envr);

/*
**	time control functions
*/
t_time_ms	my_gettime(void);
void		my_sleep(t_time_ms sleep_time);

/*
**	Philosopher life functions
*/
void		*ft_life(void *my_philo);
void		ft_exec_philo(t_philo *my_philo, int nphil, t_envr *my_envr);
void		ft_take_fork(int type, t_philo *my_philo);
void		ft_write_phil_st(int work, t_philo *my_philo);
void		*ft_ch_phil(void *data);
void		ft_take_fork(int type, t_philo *my_philo);
void		ft_check_meals(t_philo *philo);
void		*ft_philo_eat(t_philo *my_philo);
void		*ft_philo_sleep(t_philo *my_philo);
void		*ft_philo_think(t_philo *my_philo);

/*
**	utility functions
*/
int			ft_atoi(const char *str);
long int	ft_nb_size(long int n);
size_t		ft_strlen(const char *str);
void		ft_rounds(int round);

/*
**	error control functions
*/
void		ft_write_error(char *err_tit, char *errmsg);
int			ft_put_error(char *err_tit, char *errmsg, int err_n);
int			ft_file_error(int fd);

/*
** 	cleaning functions
*/
void		ft_total_clean(t_envr *myinfo);
void		ft_philos_clean(t_envr *my_envr, t_philo *philos);

#endif
