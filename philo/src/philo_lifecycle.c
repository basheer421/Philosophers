/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:57:27 by bammar            #+#    #+#             */
/*   Updated: 2023/03/05 13:05:36 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_sleep(t_thread_arg *thrd_arg)
{
	philo_msg(thrd_arg, "is sleeping\n");
	return (usleep((thrd_arg->args->sleep_time) * 1000));
}

static bool	eat(t_thread_arg *thrd_arg)
{
	t_fork			rfork;
	t_fork			lfork;

	rfork = thrd_arg->philo->forks[RIGHT];
	lfork = thrd_arg->philo->forks[LEFT];
	
	pthread_mutex_lock(rfork.mutex);
	pthread_mutex_lock(lfork.mutex);
	rfork.is_used = true;
	lfork.is_used = true;
	rfork.last_user = thrd_arg->philo->num;
	lfork.last_user = thrd_arg->philo->num;
	thrd_arg->philo->state = EATING;
	philo_msg(thrd_arg, "has taken a fork\n");
	philo_msg(thrd_arg, "has taken a fork\n");
	philo_msg(thrd_arg, "is eating\n");
	thrd_arg->philo->last_mealtime = get_mtime();
	pthread_mutex_unlock(lfork.mutex);
	pthread_mutex_unlock(rfork.mutex);
	usleep((thrd_arg->args->eat_time) * 1000);
	pthread_mutex_lock(lfork.mutex);
	pthread_mutex_lock(rfork.mutex);
	rfork.is_used = false;
	lfork.is_used = false;
	pthread_mutex_unlock(rfork.mutex);
	pthread_mutex_unlock(lfork.mutex);
	return (true);
}

static void	*die(t_thread_arg *thrd_arg)
{
	pthread_mutex_lock(thrd_arg->exit_mutex);
	if (*thrd_arg->is_exit == false)
		philo_msg(thrd_arg, "died\n");
	*(thrd_arg->is_exit) = true;
	pthread_mutex_unlock(thrd_arg->exit_mutex);
	return (NULL);
}

void	*philo_lifecycle(void *arg)
{
	t_thread_arg	*thrd_arg;
	t_fork			rfork;
	t_fork			lfork;

	thrd_arg = (t_thread_arg *)arg;
	rfork = thrd_arg->philo->forks[RIGHT];
	lfork = thrd_arg->philo->forks[LEFT];
	thrd_arg->philo->last_mealtime = get_mtime();
	while (!(*thrd_arg->is_exit))
	{
		if (get_mtime() - thrd_arg->philo->last_mealtime
			>= (time_t)thrd_arg->args->die_time)
			return (die(thrd_arg));
		else if (rfork.is_used || lfork.is_used
			|| rfork.last_user == thrd_arg->philo->num
			|| lfork.last_user == thrd_arg->philo->num
			|| thrd_arg->philo->state != THINKING)
			thrd_arg->philo->state = THINKING;
		else if (thrd_arg->philo->state != EATING)
		{
			thrd_arg->philo->state = EATING;
			eat(thrd_arg);
			
		}
		else
		{
			thrd_arg->philo->state = SLEEPING;
			philo_msg(thrd_arg, "is sleeping\n");
			philo_sleep(thrd_arg);
		}
	}
	return (NULL);
}
