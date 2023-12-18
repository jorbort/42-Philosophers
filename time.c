/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 08:21:52 by jorge             #+#    #+#             */
/*   Updated: 2023/12/18 19:21:02 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	elapsed(long start)
{
	return (find_msec() - start);
}

long	find_msec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
