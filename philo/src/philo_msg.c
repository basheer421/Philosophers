/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:10:33 by bammar            #+#    #+#             */
/*   Updated: 2023/03/11 14:20:13 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_mtime(void)
{
	struct timeval	tod;

	gettimeofday(&tod, NULL);
	return ((tod.tv_usec / 1000) + (tod.tv_sec * 1000));
}

void	philo_msg(t_thread_arg *thrd_arg, const char *msg)
{
	time_t	t;

	t = get_mtime();
	pthread_mutex_lock(thrd_arg->print_mutex);
	printf("%ld %lu %s",
		t - thrd_arg->args->start_time, thrd_arg->philo->num, msg);
	pthread_mutex_unlock(thrd_arg->print_mutex);
}
