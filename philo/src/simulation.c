/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:50:44 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/12/13 16:55:36 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *routine(void *arg)
{
    t_philos *philo = (t_philos *)arg;
    
    while (1)
    {
        take_forks(philo);
        eating(philo);
        drop_forks(philo);
        sleeping(philo);
        thinking(philo);
        
        // Cần thêm kiểm tra điều kiện dừng
    }
    return NULL;
}

void	start_simulation(t_philos *philos)
{
	int count;
	int i;

	count = philos[0].philos_count;
	i = 0;
	while (i < count)
	{
		if (pthread_create(&philos[i].thread_id, NULL, routine, &philos[i]) != 0)
			error_msg("Error: thread creation failed\n", 1);
		i++;
	}
    i = 0;
    while (i < count)
    {
        pthread_join(philos[i].thread_id, NULL);
        i++;
    }
}

void    monitor()
{
}