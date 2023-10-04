/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:58:03 by jbortolo          #+#    #+#             */
/*   Updated: 2023/10/04 15:20:15 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_program *program)
{
	program->n_of_meals = 0;
	program->t_to_die = 0;
	program->t_to_eat = 0;
	program->t_to_sleep = 0;
	program->n_of_philos = 0;
	program->flag = false;
}

void	init_forks(t_program *program)
{
	program->fork = malloc(sizeof(pthread_mutex_t) * program->n_of_philos);
}