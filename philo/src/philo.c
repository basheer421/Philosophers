/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:09:14 by bammar            #+#    #+#             */
/*   Updated: 2023/02/01 02:26:57 by bammar           ###   ########.fr       */
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
	printf("args->count:%ld\n", args.count);
	printf("args->die_time:%ld\n", args.die_time);
	printf("args->eat_time:%ld\n", args.eat_time);
	printf("args->sleep_time:%ld\n", args.sleep_time);
	if (argc == 6)
		printf("args->eat_limit:%ld\n", args.eat_limit);
	return (0);
}
