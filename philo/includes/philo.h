/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:09:02 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/12/28 14:08:11 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# define PHILO_MAX 250

# include <limits.h>
# include <pthread.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
	int				dead;
	int				must_eat;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	meal_mutex;
}	t_data;

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
	int				eat_count;
	t_times			times;
	t_mutexes		mutexes;
	pthread_t		thread_id;
	pthread_mutex_t	*print_mutex;
	t_data			*data;
}					t_philos;

typedef struct s_env
{
	int				n;
	pthread_mutex_t	forks[PHILO_MAX];
	pthread_mutex_t	print_mutex;
	t_philos		philos[PHILO_MAX];
	t_data			data;
	pthread_t		monitor_thread;
}	t_env;

// string.c
int					ft_strlen(char *s);
int					ft_atoi(char *s);

// utils.c
void				error_msg(char *msg, int ex_sign);
void				print_action(t_philos *philos, char *action);
void				ft_usleep(size_t mls);
void				cleanup(t_philos *philos, pthread_mutex_t *forks,
						pthread_mutex_t *print_mutex);
void				set_dead_flag(t_philos *philos);

//get_data.c
size_t				get_current_time(void);
void				update_last_meal(t_philos *philo);
size_t      		get_last_meal(t_philos *philo);
int		      		get_eat_count(t_philos *philo);
int					is_dead(t_philos *philo);

// init.c
void				init_data(t_data *data, int ac, char **av);
void				init_fork(pthread_mutex_t *forks, int n);
void				init_philos(t_env *env, char **av);
t_env				init_all(int ac, char **av);

// action.c
int					take_forks(t_philos *philos);
void				eating(t_philos *philos);
void				drop_forks(t_philos *philos);
void				sleeping(t_philos *philos);

// simulation.c
void				*routine(void *arg);
void				start_simulation(t_philos *philos);
void				join_threads(t_philos *philos);
int     			check_stop(t_philos *philos, int n);
void    			*monitor(void *arg);

// main.c
void				check_input(int ac, char **av);
int					main(int ac, char **av);

#endif