/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:58:45 by jbortolo          #+#    #+#             */
/*   Updated: 2023/10/04 16:13:03 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_program *program)
{
	if (i == program->n_of_philos)
	{
		pthread_mutex_lock(&program->fork[i]);
		pthread_mutex_lock(&program->fork[i - 1]);
	}
	else
	{
		pthread_mutex_lock(&program->fork[i]);
		pthread_mutex_lock(&program->fork[i + 1]);
	}
	printf("philosopher %d is eating \n", program->philos[i]);
}
