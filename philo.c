/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:56:14 by jorgebortol       #+#    #+#             */
/*   Updated: 2023/12/18 20:28:26 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->n_of_philos)
	{
		if (pthread_join(program->philos[i].ph_t, NULL) != 0)
			return (1);
		i++;
	}
	return (1);
}

static void	ft_sleep(int time)
{
	long	start;
	long	elapsed;

	start = find_msec();
	elapsed = 0;
	while (elapsed < time)
	{
		usleep(time * 1000);
		elapsed = find_msec() - start;
	}
}

static int	determine_r_fork(t_philo *philos)
{
	if (philos->id == 0)
		return (philos->program->n_of_philos - 1);
	else
		return (philos->id - 1);
}

static int	ft_eat(t_philo	*philos)
{
	int	r_fork;

	r_fork = determine_r_fork(philos);
	pthread_mutex_lock(&philos->program->forks[r_fork]);
	print_lock("has picked up a fork", philos->id, philos->program,
		elapsed(philos->program->start_t));
	pthread_mutex_lock(&philos->program->forks[philos->id]);
	print_lock("has picked up a fork", philos->id, philos->program,
		elapsed(philos->program->start_t));
	set_m_t(philos);
	philos->eat_count--;
	print_lock("is eating", philos->id, philos->program,
		elapsed(philos->program->start_t));
	ft_sleep(philos->program->t_to_eat);
	pthread_mutex_unlock(&philos->program->forks[r_fork]);
	pthread_mutex_unlock(&philos->program->forks[philos->id]);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philos;

	philos = arg;
	if (philos->id % 2 == 0)
		usleep(philos->program->t_to_eat * 1000);
	while (!check_end(philos->program) && philos->eat_count != 0)
	{
		print_lock("is thinking", philos->id, philos->program,
			elapsed(philos->program->start_t));
		ft_eat(philos);
		print_lock("is sleeping", philos->id, philos->program,
			elapsed(philos->program->start_t));
		ft_sleep(philos->program->t_to_sleep);
	}
	return (NULL);
}
