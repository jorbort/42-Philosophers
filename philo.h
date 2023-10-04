/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:27:55 by jorge             #+#    #+#             */
/*   Updated: 2023/10/04 15:18:46 by jbortolo         ###   ########.fr       */
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


typedef struct s_program
{
	int				t_to_eat;
	int				t_to_die;
	int				t_to_sleep;
	int				n_of_philos;
	int				n_of_meals;
	pthread_t		*philos;
	pthread_mutex_t	*fork;
	bool			flag;
	bool			full;
}	t_program;

//routine.c
void	routine(t_program *program);



#endif