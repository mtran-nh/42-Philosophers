/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:33:50 by mtran-nh          #+#    #+#             */
/*   Updated: 2026/01/01 22:03:26 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	one_philo_case(t_philos *philos)
{
	if (philos->philos_count == 1)
	{
		pthread_mutex_lock(philos->mutexes.left_fork);
		print_action(philos, "has taken a fork");
		while (!is_dead(philos))
			usleep(1000);
		pthread_mutex_unlock(philos->mutexes.left_fork);
		return (1);
	}
	return (0);
}

int	take_forks(t_philos *philos)
{
	if (one_philo_case(philos))
		return (0);
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->mutexes.right_fork);
		if (is_dead(philos))
			return (pthread_mutex_unlock(philos->mutexes.right_fork), 0);
		print_action(philos, "has taken a fork");
		pthread_mutex_lock(philos->mutexes.left_fork);
		if (is_dead(philos))
			return (drop_forks(philos), 0);
		print_action(philos, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philos->mutexes.left_fork);
		if (is_dead(philos))
			return (pthread_mutex_unlock(philos->mutexes.left_fork), 0);
		print_action(philos, "has taken a fork");
		pthread_mutex_lock(philos->mutexes.right_fork);
		if (is_dead(philos))
			return (drop_forks(philos), 0);
		print_action(philos, "has taken a fork");
	}
	return (1);
}

void	eating(t_philos *philos)
{
	print_action(philos, "is eating");
	update_last_meal(philos);
	ft_usleep(philos->times.eat);
}

void drop_forks(t_philos *philos)
{
	if (philos->philos_count == 1)
	{
		pthread_mutex_unlock(philos->mutexes.left_fork);
		return ;
	}
    if (philos->mutexes.left_fork)
        pthread_mutex_unlock(philos->mutexes.left_fork);
    if (philos->mutexes.right_fork)
        pthread_mutex_unlock(philos->mutexes.right_fork);
}

void	sleeping(t_philos *philos)
{
	print_action(philos, "is sleeping");
	ft_usleep(philos->times.sleep);
}
