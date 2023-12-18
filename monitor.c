/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:23:44 by jorgebortol       #+#    #+#             */
/*   Updated: 2023/12/18 20:31:13 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_monitoring(t_program *program)
{
	int		i;
	long	diff_meal;

	i = 0;
	while (i < program->n_of_philos)
	{
		diff_meal = find_msec() - read_m_t(&program->philos[i]);
		if (program->t_to_die < diff_meal)
		{
			change_end(program);
			if (program->philos[i].eat_count != 0)
				printf("%ld Philosopher %d has died\n",
					elapsed(program->start_t), program->philos[i].id);
			return ;
		}
		i++;
	}
}

void	ft_monitor(t_program *program)
{
	while (!check_end(program))
	{
		ft_monitoring(program);
		usleep(1000);
	}
	free_ph_n_forks(program);
}
