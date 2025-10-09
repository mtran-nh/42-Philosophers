/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:09:02 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/10/06 17:10:05 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# define PHILO_MAX 200

# include <limits.h>
# include <pthread.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_mutexes
{
}			t_mutexes;

typedef struct s_times
{
	size_t	die;
	size_t	eat;
	size_t	sleep;
}			t_times;

typedef struct s_philos
{
	int		philos_count;
	t_times	times;
}			t_philos;

int			ft_strlen(char *s);
void		error_msg(char *msg, int ex_sign);
int			ft_atoi(char *s);

void		check_input(int ac, char **av);

#endif