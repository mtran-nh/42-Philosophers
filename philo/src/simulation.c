/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:50:44 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/12/20 01:11:08 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *routine(void *arg)
{
    t_philos *philo = (t_philos *)arg;
    
    printf("DEBUG routine: Philosopher %d started\n", philo->id);
    
    while (!is_dead(philo))
    {
        if (is_dead(philo))
            break;
        take_forks(philo);
        if (is_dead(philo))
        {
            drop_forks(philo);
            break;
        }
        eating(philo);
        drop_forks(philo);
        if (is_dead(philo))
            break;
        sleeping(philo);
        if (is_dead(philo))
            break;
        thinking(philo);
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
}

void	join_threads(t_philos *philos)
{
	int count;
	int i;

	count = philos[0].philos_count;
	i = 0;
	while (i < count)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
}

int     check_stop(t_philos *philos, int n)
{
    int     i;

    pthread_mutex_lock(&philos[0].data->dead_mutex);
    if (philos[0].data->dead == 1)
    {
        pthread_mutex_unlock(&philos[0].data->dead_mutex);
        return (1);
    }
    pthread_mutex_unlock(&philos[0].data->dead_mutex);
    i = -1;
    while (++i < n)
    {
        if ((get_current_time() - get_last_meal(&philos[i])) > philos[i].times.die)
            return (set_dead_flag(philos), print_action(&philos[i], "died"), 1);
    }
    if (philos[0].data->must_eat > 0)
    {
        i = -1;
        while (++i < n)
            if (get_eat_count(&philos[i]) < philos[0].data->must_eat)
                return 0;
        return (set_dead_flag(philos), 1);
    }
    return (0);
}

void    *monitor(void *arg)
{
    t_philos *philos = (t_philos *)arg;
    int     n;
    
    printf("DEBUG monitor: Starting\n");
    n = philos->philos_count;
    
    printf("DEBUG monitor: n = %d\n", n);
    while (!check_stop(philos, n))
        usleep(1000);
     printf("DEBUG monitor: Exiting\n");
    return (NULL);
}
