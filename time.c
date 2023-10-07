/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 08:21:52 by jorge             #+#    #+#             */
/*   Updated: 2023/10/07 08:37:33 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	elapsed(long start)
{
	return (find_msec - start);
}

long	find_msec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);

	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
