/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:09:14 by bammar            #+#    #+#             */
/*   Updated: 2023/02/04 23:07:07 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
}

int	main(int argc, char **argv)
{
	t_philo_args	args;
	pthread_t		*philos;
	pthread_mutex_t	*forks;

	if (argc != 5 && argc != 6)
		return (1);
	if (!fill_philo_args(argc, argv, &args))
		return (print_error("Error\nIncorrect arguments\n"), 1);
	philos = malloc(sizeof(pthread_t) * (args.count + 1));
	if (!philos)
		return (1);
	forks = malloc(sizeof(pthread_mutex_t) * (args.count + 1));
	if (!forks)
		return (free(philos), 1);
	// forks = pthread_mutex_init(fokrs)
	free(philos);
	return (0);
}
