/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:17:38 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/10/17 15:54:32 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	init_philos(t_philos *philos, pthread_mutex_t *forks, char **av)
{
	int	i;
	int	n;

	n = ft_atoi(av[1]);
	i = 0;
	while (i < n)
	{
		philos[i].id = i + 1;
		philos[i].philos_count = n;
		philos[i].times.die = ft_atoi(av[2]);
		philos[i].times.eat = ft_atoi(av[3]);
		philos[i].times.sleep = ft_atoi(av[4]);
		philos[i].times.start_time = get_current_time();
		philos[i].times.last_meal = get_current_time();
		philos[i].mutexes.left_fork = &forks[i];
		philos[i].mutexes.right_fork = &forks[(i + 1) % n];
		i++;
	}
}
