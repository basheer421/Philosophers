/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:06:46 by bammar            #+#    #+#             */
/*   Updated: 2023/02/05 03:21:11 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	left_fork(int i, int n)
{
	if (i - 1 < 0)
		return (n - 1);
	return (i - 1);
}

static int	right_fork(int i, int n)
{
	if (i + 1 == n)
		return (0);
	return (i + 1);
}

bool	philo_init(t_philo_args *args, t_philo ***philos,
			pthread_mutex_t **forks)
{
	size_t	i;

	*forks = malloc(sizeof(pthread_mutex_t) * (args->count));
	if (!*forks)
		return (false);
	*philos = malloc(sizeof(t_philo *) * (args->count + 1));
	if (!(*philos))
		return (false);
	i = 0;
	while (i < args->count)
	{
		(*philos)[i] = malloc(sizeof(t_philo));
		if (!(*philos)[i])
			return (false);
		(*philos)[i]->thread = malloc(sizeof(pthread_t));
		if (!(*philos)[i]->thread)
			return (false);
		(*philos)[i]->num = i + 1;
		(*philos)[i]->state = THINKING;
		(*philos)[i]->forks[RIGHT] = &(forks[0][right_fork(i, args->count)]);
		(*philos)[i]->forks[LEFT] = &(forks[0][left_fork(i, args->count)]);
		i++;
	}
	(*philos)[i] = NULL;
	return (true);
}

void	philo_destroy(t_philo **philos, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	while (philos[++i])
	{
		free(philos[i]->thread);
		free(philos[i]);
	}
	free(philos);
	free(forks);
}
