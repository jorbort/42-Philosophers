/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:27:55 by jorge             #+#    #+#             */
/*   Updated: 2023/12/18 20:57:45 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdio.h>

# define MAX_PHILOS 200

typedef struct s_philo
{
	struct s_program	*program;
	int					id;
	int					eat_count;
	long				last_meal;
	pthread_t			ph_t;
}	t_philo;

typedef struct s_program
{
	int				t_to_eat;
	int				t_to_die;
	int				t_to_sleep;
	int				n_of_philos;
	int				n_of_meals;
	long			start_t;
	pthread_mutex_t	*forks;
	pthread_mutex_t	status;
	pthread_mutex_t	meal_time;
	bool			flag;
	t_philo			*philos;
}	t_program;

//time.c
long	find_msec(void);
long	elapsed(long start);
//utils.c
int		ft_atoi(char *str, int *ret);
void	free_ph_n_forks(t_program *program);
void	print_lock(char *str, int id, t_program *program, long ms);
//mutex.c
long	read_m_t(t_philo *philos);
int		check_end(t_program *program);
void	change_end(t_program *program);
void	set_m_t(t_philo *philos);
//philo.c
int		join_threads(t_program *program);
void	*routine(void *arg);
//monitor.c
void	ft_monitor(t_program *program);
#endif