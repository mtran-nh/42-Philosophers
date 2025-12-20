/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:17:38 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/12/20 00:57:18 by mtran-nh         ###   ########.fr       */
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

void	init_philos(t_env *env, char **av)
{
	int	i;
	int	n;
	size_t start;

	start = get_current_time();
	n = ft_atoi(av[1]);
	i = -1;
	while (++i < n)
	{
		env->philos[i].id = i + 1;
		env->philos[i].philos_count = n;
		env->philos[i].times.die = ft_atoi(av[2]);
		env->philos[i].times.eat = ft_atoi(av[3]);
		env->philos[i].times.sleep = ft_atoi(av[4]);
		env->philos[i].times.start_time = start;
		env->philos[i].times.last_meal = get_current_time();
		printf("DEBUG init: Philosopher %d last_meal initialized to %zu\n", 
    i + 1, env->philos[i].times.last_meal);
		
		env->philos[i].mutexes.left_fork = &env->forks[i];
		if (n == 1)
            env->philos[i].mutexes.right_fork = NULL;
        else
            env->philos[i].mutexes.right_fork = &env->forks[(i + 1) % n];
		env->philos[i].print_mutex = &env->print_mutex;
		env->philos[i].data = &env->data;
		env->philos[i].eat_count = 0;
	}
}

t_env	init_all(int ac, char **av)
{
	t_env	env;
	
	env.n = ft_atoi(av[1]);
	init_data(&env.data, ac, av);
	if (pthread_mutex_init(&env.print_mutex, NULL) != 0)
		error_msg("Error: print mutex init failed", 1);
	init_fork(env.forks, env.n);
	init_philos(&env, av);
	return (env);
}
