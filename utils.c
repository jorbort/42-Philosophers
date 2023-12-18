/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:49:15 by jorge             #+#    #+#             */
/*   Updated: 2023/12/18 21:06:09 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_atoi(char *str, int *ret)
{
	int		p_n;
	int		i;

	i = 0;
	p_n = 1;
	if (*str == '-' && *str)
	{
		p_n *= -1;
		str++;
	}
	if (!*str)
		return (1);
	while (str[i])
	{
		if (is_digit(str[i]) == 1)
			*ret = (*ret * 10) + (str[i++] - '0');
		else
			return (1);
		if (*ret * p_n > 2147483647 || *ret * p_n < -2147483648)
			return (1);
	}
	*ret = *ret * p_n;
	return (0);
}

void	free_ph_n_forks(t_program *program)
{
	free(program->philos);
	free(program->forks);
}

void	print_lock(char *str, int id, t_program *program, long ms)
{
	pthread_mutex_lock(&program->status);
	if (!program->flag)
		printf("%ld philosopher %i %s\n", ms, id, str);
	pthread_mutex_unlock(&program->status);
}
