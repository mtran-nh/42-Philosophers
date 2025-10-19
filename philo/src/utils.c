/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:15:03 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/10/19 18:41:36 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_msg(char *msg, int ex_sign)
{
	if (msg)
		write(1, msg, ft_strlen(msg));
	exit(ex_sign);
}

size_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
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
