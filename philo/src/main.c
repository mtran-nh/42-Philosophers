/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:32:49 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/12/13 17:00:58 by mtran-nh         ###   ########.fr       */
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
	t_env			env;

	check_input(ac, av);
	init_all(ac, av);
	start_simulation(env.philos);
	pthread_create(&env.monitor_thread, NULL, monitor, env.philos);
	pthread_join(env.monitor_thread, NULL);
	cleanup(env.philos, env.forks, &env.print_mutex);
	pthread_mutex_destroy(&env.data.dead_mutex);
	pthread_mutex_destroy(&env.data.meal_mutex);
}

// THỨ TỰ LÀM KHUYÊN DÙNG

// 1 data struct
// 2 mutex bảo vệ last_meal
// 3 monitor thread
// 4 stop simulation
// 5 eat limit
// 6 case 1 philosopher