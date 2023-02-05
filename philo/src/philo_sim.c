/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 02:56:38 by bammar            #+#    #+#             */
/*   Updated: 2023/02/05 03:55:40 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_sim(t_philo *philos, t_philo_args *args)
{
	size_t			i;
	t_thread_arg	thrd_arg;

	i = 0;
	while (i < args->count)
	{
		thrd_arg.args = args;
		thrd_arg.philo = &philos[i];
		if (pthread_create(philos[i++].thread, NULL,
			philo_lifecycle, &thrd_arg) != 0)
			return (false);
	}
	i = 0;
	while (i < args->count)
	{
		pthread_join(*(philos[i++].thread), NULL);
	}
	return (true);
}
