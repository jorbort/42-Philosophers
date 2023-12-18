/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:34:09 by jorgebortol       #+#    #+#             */
/*   Updated: 2023/12/18 20:37:37 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end(t_program *program)
{
	int	status;

	pthread_mutex_lock(&program->status);
	if (program->flag)
		status = 1;
	else
		status = 0;
	pthread_mutex_unlock(&program->status);
	return (status);
}

void	change_end(t_program *program)
{
	pthread_mutex_lock(&program->status);
	program->flag = true;
	pthread_mutex_unlock(&program->status);
}

void	set_m_t(t_philo *philos)
{
	pthread_mutex_lock(&philos->program->meal_time);
	philos->last_meal = find_msec();
	pthread_mutex_unlock(&philos->program->meal_time);
}

long	read_m_t(t_philo *philos)
{
	long	last_m_time;

	pthread_mutex_lock(&philos->program->meal_time);
	last_m_time = philos->last_meal;
	pthread_mutex_unlock(&philos->program->meal_time);
	return (last_m_time);
}
