/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:56:30 by bammar            #+#    #+#             */
/*   Updated: 2023/02/17 14:04:24 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <string.h>

# define RIGHT 0
# define LEFT 1

typedef enum philo_state
{
	THINKING,
	EATING,
	SLEEPING
}	t_philo_state;

/*
	size_t:
	count;
	die_time;
	eat_time;
	sleep_time;
	eat_limit;
	is_limited -> bool

	Eat limit is set to -1 when it's not given.
*/
typedef struct s_philo_args
{
	size_t	count;
	size_t	die_time;
	size_t	eat_time;
	size_t	sleep_time;
	size_t	eat_limit;
	bool	is_limited;
}	t_philo_args;

typedef struct s_fork
{
	bool			is_used;
	pthread_mutex_t	*mutex;
}	t_fork;

typedef struct s_philo
{
	size_t			num;
	t_philo_state	state;
	size_t			eat_count;
	t_fork			forks[2];
	pthread_t		*thread;
	time_t			last_mealtime;
}	t_philo;

typedef struct s_thread_arg
{
	t_philo			*philo;
	t_philo_args	*args;
}	t_thread_arg;

long	ft_atol(const char *str);
int 	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_index(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
bool	fill_philo_args(int argc, char **argv, t_philo_args *args);
bool	philo_init(t_philo_args *args, t_philo ***philos,
			pthread_mutex_t ***forks);
void	philo_destroy(t_philo **philos, pthread_mutex_t **forks);
bool	philo_sim(t_philo **philos, t_philo_args *args);
void	*philo_lifecycle(void *arg);
time_t	get_mtime(void);
void	philo_msg(size_t philo_num, const char *msg);

#endif