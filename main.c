/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgebortolotti <jorgebortolotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:36:50 by jorge             #+#    #+#             */
/*   Updated: 2023/12/18 21:10:46 by jorgebortol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	parse_args(char **argv, t_program *program, int argc)
{
	program->n_of_philos = 0;
	program->n_of_meals = 0;
	program->t_to_die = 0;
	program->t_to_eat = 0;
	program->t_to_sleep = 0;
	program->start_t = find_msec();
	program->flag = false;
	if (ft_atoi(argv[1], &program->n_of_philos)
		|| ft_atoi(argv[2], &program->t_to_die)
		|| ft_atoi(argv[3], &program->t_to_eat)
		|| ft_atoi(argv[4], &program->t_to_sleep))
		return (0);
	if (program->n_of_philos < 1)
		return (0);
	if (argc == 6)
	{
		if (ft_atoi(argv[5], &program->n_of_meals))
			return (0);
	}
	else
		program->n_of_meals = -1;
	return (1);
}

static bool	create_philo(t_program *program, int i)
{
	program->philos[i].id = i;
	program->philos[i].last_meal = find_msec();
	program->philos[i].program = program;
	program->philos[i].eat_count = program->n_of_meals;
	if (pthread_create
		(&program->philos[i].ph_t, NULL, &routine, &program->philos[i]))
		return (false);
	return (true);
}

static bool	malloc_ph_n_forks(t_program *program)
{
	if (pthread_mutex_init(&program->status, NULL))
		return (false);
	if (pthread_mutex_init(&program->meal_time, NULL))
		return (false);
	program->philos = malloc(sizeof(t_philo) * program->n_of_philos);
	if (!program->philos)
		return (false);
	program->forks = malloc(sizeof(pthread_mutex_t) * program->n_of_philos);
	if (!program->forks)
	{
		free(program->philos);
		return (false);
	}
	return (true);
}

static bool	init_ph_n_forks(t_program *program)
{
	int	i;

	i = 0;
	if (!malloc_ph_n_forks(program))
		return (false);
	while (i < program->n_of_philos)
	{
		if (pthread_mutex_init(&program->forks[i++], NULL))
		{
			free_ph_n_forks(program);
			return (false);
		}
	}
	i = 0;
	while (i < program->n_of_philos)
	{
		if (!create_philo(program, i))
		{
			free_ph_n_forks(program);
			return (false);
		}
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_program	program;


	if (argc != 5 && argc != 6)
	{
		printf("invalid number of arguments");
		return (1);
	}
	if (!parse_args(argv, &program, argc))
	{
		printf("invalid arguments value");
		return (1);
	}
	if (!init_ph_n_forks(&program))
	{
		printf("Malloc error");
		return (1);
	}
	ft_monitor(&program);
	join_threads(&program);
	return (0);
}
