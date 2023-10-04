/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:49:15 by jorge             #+#    #+#             */
/*   Updated: 2023/10/03 10:07:42 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

void	ft_atoi(char *str, t_program *program, int argc)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (argc == 1)
		program->n_of_philos = n;
	if (argc == 2)
		program->t_to_die = n;
	if (argc == 3)
		program->t_to_eat = n;
	if (argc == 4)
		program->t_to_sleep = n;
	if (argc == 5)
		program->n_of_meals = n;
}

bool	atoi_check(char **str, t_program *program)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-')
			return (false);
		while (str[i][j])
		{
			if (is_digit(str[i][j]) == false)
				return (false);
			j++;
		}
		i++;
	}
	i = 0;
	ft_atoi(str[i], program, i);
	return (true);
}
