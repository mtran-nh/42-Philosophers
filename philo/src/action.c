/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:33:50 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/12/13 13:49:07 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void        take_forks(t_philos *philos)
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

void        eating(t_philos *philos)
{
    print_action(philos, "is eating");
    philos->times.last_meal = get_current_time();
    ft_usleep(philos->times.eat);
}

void        drop_forks(t_philos *philos)
{
    pthread_mutex_unlock(philos->mutexes.left_fork);
    pthread_mutex_unlock(philos->mutexes.right_fork);
}

void        sleeping(t_philos *philos)
{
    print_action(philos, "is sleeping");
    ft_usleep(philos->times.sleep);
}

void        thinking(t_philos *philos)
{
    print_action(philos, "is thinking");
}