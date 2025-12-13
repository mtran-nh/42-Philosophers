/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:17:38 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/12/13 16:59:58 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_data(t_data *data, int ac, char **av)
{
	data->dead = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	if (pthread_mutex_init(&data->dead_mutex, NULL) != 0)
		error_msg("Error: dead mutex init failed\n", 1);
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0)
		error_msg("Error: meal mutex init failed\n", 1);
}

void	init_fork(pthread_mutex_t *forks, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			error_msg("Error: Forks initialization failed\n", 1);
			return ;
		}
		i++;
	}
}

void	init_philos(t_philos *philos, pthread_mutex_t *forks,
		pthread_mutex_t *print_mutex, char **av)
{
	int	i;
	int	n;
	size_t start;

	start = get_current_time();
	n = ft_atoi(av[1]);
	i = 0;
	while (i < n)
	{
		philos[i].id = i + 1;
		philos[i].philos_count = n;
		philos[i].times.die = ft_atoi(av[2]);
		philos[i].times.eat = ft_atoi(av[3]);
		philos[i].times.sleep = ft_atoi(av[4]);
		philos[i].times.start_time = start;
		philos[i].times.last_meal = get_current_time();
		philos[i].mutexes.left_fork = &forks[i];
		philos[i].mutexes.right_fork = &forks[(i + 1) % n];
		philos[i].print_mutex = print_mutex;
		i++;
	}
}

void	init_all(int ac, char **av)
{
	t_env	env;
	
	env.n = ft_atoi(av[1]);
	init_data(&env.data, ac, av);
	if (pthread_mutex_init(&env.print_mutex, NULL) != 0)
		error_msg("Error: print mutex init failed", 1);
	init_fork(env.forks, env.n);
	init_philos(env.philos, env.forks, &env.print_mutex, av);
}
