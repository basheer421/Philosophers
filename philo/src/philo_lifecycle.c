/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:57:27 by bammar            #+#    #+#             */
/*   Updated: 2023/02/06 00:12:04 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	eat(t_thread_arg *thrd_arg)
{
	t_fork			rfork;
	t_fork			lfork;

	rfork = thrd_arg->philo->forks[RIGHT];
	lfork = thrd_arg->philo->forks[LEFT];
	rfork.is_used = true;
	lfork.is_used = true;
	if (pthread_mutex_lock(rfork.mutex) != 0
		|| pthread_mutex_lock(lfork.mutex) != 0)
		return (false);
	philo_msg(thrd_arg->philo->num, "has taken a fork\n");
	philo_msg(thrd_arg->philo->num, "has taken a fork\n");
	philo_msg(thrd_arg->philo->num, "is eating\n");
	usleep((thrd_arg->args->eat_time) * 1000);
	if (pthread_mutex_unlock(rfork.mutex) != 0
		|| pthread_mutex_unlock(lfork.mutex) != 0)
		return (false);
	return (true);
}

static bool	philo_sleep(t_thread_arg *thrd_arg)
{
	philo_msg(thrd_arg->philo->num, "is sleeping\n");
	return (usleep((thrd_arg->args->sleep_time) * 1000));
}

static void	*die(t_thread_arg *thrd_arg)
{
	philo_msg(thrd_arg->philo->num, "died\n");
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
	printf("philinum: %d\n", thrd_arg->philo->num);
	printf("rfork:%p\nlfork:%p\n", rfork.mutex, lfork.mutex);
	thrd_arg->philo->last_mealtime = get_mtime();
	while (true)
	{
		if (get_mtime() - thrd_arg->philo->last_mealtime
			>= (time_t)thrd_arg->args->die_time)
			return (die(thrd_arg));
		if (rfork.is_used || lfork.is_used)
			thrd_arg->philo->state = THINKING;
		else
		{
			if (!eat(thrd_arg))
				return (NULL);
			philo_sleep(thrd_arg);
		}
	}
	return (NULL);
}
