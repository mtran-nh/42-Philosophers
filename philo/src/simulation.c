/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:50:44 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/10/19 19:19:56 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    take_forks(t_philos *philos)
{
    if (philos->id % 2 == 0)
    {
        pthread_mutex_lock(philos->mutexes.right_fork);
        print_action(philos, "has taken a fork");
        pthread_mutex_lock(philos->mutexes.left_fork);
        print_action(philos, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(philos->mutexes.left_fork);
        print_action(philos, "has taken a fork");
        pthread_mutex_lock(philos->mutexes.right_fork);
        print_action(philos, "has taken a fork");
    }
}

void	routine(void)
{
}

void	start_simulation(t_philos *philos)
{
	int count;
	int i;

	count = philos[0].philos_count;
	i = 0;
	while (i < count)
	{
		if (pthread_create(philos[i].thread_id, NULL, routine, &philos[i]) != 0)
			error_msg("Error: thread creation failed\n", 1);
		i++;
	}
}