/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:57:27 by bammar            #+#    #+#             */
/*   Updated: 2023/02/05 04:15:08 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_lifecycle(void *arg)
{
	t_thread_arg	*thrd_arg;
	pthread_mutex_t *rfork;
	pthread_mutex_t *lfork;

	thrd_arg = (t_thread_arg *)arg;
	if (thrd_arg->philo->state == THINKING)
	{
		rfork = thrd_arg->philo->forks[RIGHT];

	}
	return (NULL);
}
