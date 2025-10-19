/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:09:02 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/10/19 18:59:25 by mtran-nh         ###   ########.fr       */
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
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_mutexes;

typedef struct s_times
{
	size_t			die;
	size_t			eat;
	size_t			sleep;
	size_t			start_time;
	size_t			last_meal;
}					t_times;

typedef struct s_philos
{
	int				id;
	int				philos_count;
	t_times			times;
	t_mutexes		mutexes;
	pthread_t		thread_id;
	pthread_mutex_t	*print_mutex;
}					t_philos;

// string.c
int					ft_strlen(char *s);
int					ft_atoi(char *s);

// utils.c
void				error_msg(char *msg, int ex_sign);
size_t				get_current_time(void);
void				ft_usleep(size_t mls);
void				cleanup(t_philos *philos, pthread_mutex_t *forks,
						pthread_mutex_t *print_mutex);

// init.c
void				init_fork(pthread_mutex_t *forks, int n);
void				init_philos(t_philos *philos, pthread_mutex_t *forks,
						pthread_mutex_t *print_mutex, char **av);

// simulation.c
void				start_simulation(t_philos *philos);

// main.c
void				check_input(int ac, char **av);
int					main(int ac, char **av);

#endif