/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:15:03 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/12/20 01:13:24 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_msg(char *msg, int ex_sign)
{
	if (msg)
		write(1, msg, ft_strlen(msg));
	exit(ex_sign);
}

void	print_action(t_philos *philos, char *action)
{
	size_t		time;

	pthread_mutex_lock(philos->print_mutex);
	time = get_current_time() - philos->times.start_time;
	printf("%zu %d %s\n", time, philos->id, action);
	pthread_mutex_unlock(philos->print_mutex);
}

void	ft_usleep(size_t mls)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < mls)
		usleep(500);
}

void	cleanup(t_philos *philos, pthread_mutex_t *forks,
		pthread_mutex_t *print_mutex)
{
	int i;
	int n;

	n = philos[0].philos_count;
	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&forks[i]);
	pthread_mutex_destroy(print_mutex);
}

void	set_dead_flag(t_philos *philos)
{
	pthread_mutex_lock(&philos[0].data->dead_mutex);
	philos->data->dead = 1;
	pthread_mutex_unlock(&philos[0].data->dead_mutex);
}
