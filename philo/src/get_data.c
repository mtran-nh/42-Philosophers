/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:31:21 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/12/19 22:31:21 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	update_last_meal(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->meal_mutex)
	philo->times.last_meal = get_current_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo.data.meal_mutex)
}

size_t      get_last_meal(t_philos *philo)
{
    size_t      last_meal;
    pthread_mutex_lock(&philo->data->meal_mutex);
    last_meal = philo->times.last_meal;
    pthread_mutex_unlock(&philo->data->meal_mutex);
}

size_t      get_last_meal(t_philos *philo)
{
    int     eat_count;
    pthread_mutex_lock(&philo->data->meal_mutex);
    eat_count = philo->eat_count;
    pthread_mutex_unlock(&philo->data->meal_mutex);
    return (eat_count);
}
