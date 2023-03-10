/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 02:56:38 by bammar            #+#    #+#             */
/*   Updated: 2023/03/11 15:36:55 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_sim(t_philo **philos, t_philo_args *args)
{
	size_t			i;
	t_thread_arg	*thrd_arg;
	bool			is_exit;
	pthread_mutex_t	exit_mutex;
	pthread_mutex_t	print_mutex;
	
	thrd_arg = malloc((sizeof(t_thread_arg)) * (args->count + 1));
	if (!thrd_arg)
		return (NULL);
	pthread_mutex_init(&(exit_mutex), NULL);
	pthread_mutex_init(&(print_mutex), NULL);
	is_exit = false;
	i = 0;
	while (i < args->count)
	{
		thrd_arg[i].args = args;
		thrd_arg[i].philo = philos[i];
		thrd_arg[i].is_exit = &is_exit;
		thrd_arg[i].exit_mutex = &exit_mutex;
		thrd_arg[i].print_mutex = &print_mutex;
		if (pthread_create(philos[i]->thread, NULL,
			philo_lifecycle, &thrd_arg[i]) != 0)
			{
				return (false);
			}
		// usleep(150);
		i++;
	}
	
	i = 0;
	while (i < args->count)
	{
		pthread_join(*(philos[i++]->thread), NULL);
	}
	return (true);
}
