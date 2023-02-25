/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:09:14 by bammar            #+#    #+#             */
/*   Updated: 2023/02/22 19:44:25 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
}

int	main(int argc, char **argv)
{
	t_philo_args	args;
	pthread_mutex_t	**forks;
	t_philo			**philos;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	if (!fill_philo_args(argc, argv, &args))
		return (print_error("Error\nIncorrect arguments\n"), EXIT_FAILURE);
	if (!philo_init(&args, &philos, &forks))
		return (EXIT_FAILURE);
	if (!philo_sim(philos, &args))
		return (philo_destroy(philos, forks), EXIT_FAILURE); 
	return (philo_destroy(philos, forks), EXIT_SUCCESS);
}
