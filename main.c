/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:36:50 by jorge             #+#    #+#             */
/*   Updated: 2023/10/07 08:48:35 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	parse_args(char **argv, t_program *program)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (atoi_check(argv[i], program) == false)
		{
			return (false);
		}
	}
	if (program->n_of_philos > MAX_PHILOS || program->n_of_philos < 1)
	{
		printf("Invalid number of philos");
		return (false);
	}
	return (true);
}

bool	check_args(int argc, char **argv, t_program *program)
{
	if (argc < 5)
	{
		printf("ARG ERROR , Too few args");
		return (false);
	}
	else if (argc > 6)
	{
		printf("ARG ERROR - Too many args");
		return (false);
	}
	return (true);
}

void	start_program(t_program *program)
{
	int	i;

	i = 0;
	program->philos = malloc(sizeof(pthread_t *) * program->n_of_philos);
	while (i < program->n_of_philos)
	{
		pthread_create(&program->philos[i], NULL, routine, NULL);
		i++;
	}
	i = 0;
	while (i < program->n_of_philos)
	{
		pthread_join(&program->philos[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_program	*program;

	program = malloc(sizeof(t_program *));
	init_struct(program);
	if (check_args == true)
	{
		if (parse_args(argv, program) == true)
		{
			start_program(program);
		}
		else
		{
			free(program);
			printf("ERROR - Found non numerical values");
		}
	}
	else
	{
		free(program);
	}
}
