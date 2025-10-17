/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:32:49 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/10/17 15:56:38 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_input(int ac, char **av)
{
	int	i;
	int	num;

	if (ac < 5 || ac > 6)
		error_msg("Error: expected 4 or 5 arguments\n", 1);
	i = 0;
	while (++i < ac)
	{
		num = ft_atoi(av[i]);
		if (i == 1 && (num < 1 || num > PHILO_MAX))
			error_msg("Error: Invalid argument\n", 1);
		else if (i == 5 && (num < 0 || num > INT_MAX))
			error_msg("Error: Invalid argument\n", 1);
		else if ((i != 1 && i != 5) && (num < 1 || num > INT_MAX))
			error_msg("Error: Invalid argument\n", 1);
	}
}

int	main(int ac, char **av)
{
	int				n;
	pthread_mutex_t	forks[PHILO_MAX];
	t_philos		philos[PHILO_MAX];
	pthread_mutex_t	print_mutex;

	check_input(ac, av);
	n = ft_atoi(av[1]);
	if (pthread_mutex_init(&print_mutex, NULL) != 0)
		error_msg("Error: print mutex init failed", 1);
	init_fork(forks, n);
	init_philos(philos, forks, av);
}
