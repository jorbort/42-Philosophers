/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:58:45 by jbortolo          #+#    #+#             */
/*   Updated: 2023/10/07 08:10:52 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// locks two forks to eat
void	eat(t_program *program, int index)
{
	if (index == program->n_of_philos)
	{
		pthread_mutex_lock(&program->fork[index]);
		pthread_mutex_lock(&program->fork[0]);
	}
	else
	{
		pthread_mutex_lock(&program->fork[index]);
		pthread_mutex_lock(&program->fork[index + 1]);
	}
	printf("philosopher %d is eating \n", index);
	usleep(program->t_to_eat);
	program->n_of_meals--;
}

// unlocks the forks and starts thinking
void	think(t_program *program, int index)
{
	if (index == program->n_of_philos)
	{
		pthread_mutex_unlock(&program->fork[index]);
		pthread_mutex_unlock(&program->fork[index - 1]);
	}
	else
	{
		pthread_mutex_unlock(&program->fork[index]);
		pthread_mutex_unlock(&program->fork[index + 1]);
	}
	printf("philosopher %d is thinking\n", index);
}

//set a usleep of the time the philosopher must sleep
void	sleeping(t_program *program, int index)
{
	printf("philosopher %d is sleeping\n", index);
	usleep(program->t_to_sleep);
}
