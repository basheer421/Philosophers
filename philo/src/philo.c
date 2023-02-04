/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:09:14 by bammar            #+#    #+#             */
/*   Updated: 2023/02/04 15:43:26 by bammar           ###   ########.fr       */
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

	if (argc != 5 && argc != 6)
		return (1);
	if (!fill_philo_args(argc, argv, &args))
		return (print_error("Error\nIncorrect arguments\n"), 1);
	return (0);
}
