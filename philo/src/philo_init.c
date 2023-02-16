/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:06:46 by bammar            #+#    #+#             */
/*   Updated: 2023/02/17 01:25:38 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	left_fork(int i, int n)
{
	(void) n;
	return (i);
}

static int	right_fork(int i, int n)
{
	if (i == n - 1)
		return (0);
	return (i + 1);
}

static bool	forks_init(pthread_mutex_t ***forks, size_t count)
{
	size_t	i;

	*forks = malloc(sizeof(pthread_mutex_t *) * (count + 1));
	if (!*forks)
		return (false);
	i = 0;
	while (i < count)
	{
		(*forks)[i] = malloc(sizeof(pthread_mutex_t));
		if (!(*forks)[i])
			return (false);
		if (pthread_mutex_init((*forks)[i], NULL) != 0)
			return (false);
		i++;
	}
	(*forks)[i] = NULL;
	return (true);
}

bool	philo_init(t_philo_args *args, t_philo ***philos,
			pthread_mutex_t ***forks)
{
	size_t	i;

	*philos = malloc(sizeof(t_philo *) * (args->count + 1));
	if (!(*philos))
		return (false);
	forks_init(forks, args->count);
	i = 0;
	while (i < args->count)
	{
		(*philos)[i] = malloc(sizeof(t_philo));
		if (!(*philos)[i])
			return (false);
		(*philos)[i]->eat_count = 0;
		(*philos)[i]->last_mealtime = get_mtime();
		(*philos)[i]->state = THINKING;
		(*philos)[i]->forks[0].is_used = false;
		(*philos)[i]->forks[1].is_used = false;
		(*philos)[i]->thread = malloc(sizeof(pthread_t));
		if (!(*philos)[i]->thread)
			return (false);
		(*philos)[i]->num = i + 1;
		(*philos)[i]->forks[RIGHT].mutex = &((**forks)[right_fork(i, args->count)]);
		(*philos)[i]->forks[LEFT].mutex = &((**forks)[left_fork(i, args->count)]);
		i++;
	}
	(*philos)[i] = NULL;
	return (true);
}

void	philo_destroy(t_philo **philos, pthread_mutex_t **forks)
{
	int	i;

	i = -1;
	while (philos[++i])
	{
		free(philos[i]->thread);
		free(philos[i]);
		pthread_mutex_destroy(forks[i]);
		free(forks[i]);
	}
	free(forks);
	free(philos);
}
