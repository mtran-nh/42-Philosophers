/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:17:38 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/10/10 16:32:00 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_fork(pthread_mutex_t *forks, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			error_msg("Error: Forks initialization failed\n", 1);
			return ;
		}
		i++;
	}
}
