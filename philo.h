/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:27:55 by jorge             #+#    #+#             */
/*   Updated: 2023/10/09 08:08:53 by jorge            ###   ########.fr       */
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
	pthread_t			t1;
	int					id;
	int					eat_count;
	int					status;
	int					eating;
	unsigned int		time_to_die;
	pthread_mutex_t		lock;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
}	t_philo;

typedef struct s_program
{
	int				t_to_eat;
	int				t_to_die;
	int				t_to_sleep;
	int				n_of_philos;
	int				n_of_meals;
	pthread_t		*t_id;
	pthread_mutex_t	*forks;
	bool			flag;
	bool			full;
	t_philo			*philos;
}	t_program;
//routine.c
void	routine(t_program *program);
#endif