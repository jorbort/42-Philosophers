/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:10:35 by jbortolo          #+#    #+#             */
/*   Updated: 2023/10/04 15:41:18 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_program *program)
{
	pthread_mutex_init(&program->fork, NULL);
	while (program->flag == false || program->n_of_meals != 0)
	{
		
	}
}
