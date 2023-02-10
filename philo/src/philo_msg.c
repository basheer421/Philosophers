/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:10:33 by bammar            #+#    #+#             */
/*   Updated: 2023/02/05 17:33:32 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_mtime(void)
{
	struct timeval	tod;

	gettimeofday(&tod, NULL);
	return ((tod.tv_usec / 1000) + (tod.tv_sec * 1000));
}

void	philo_msg(size_t philo_num, const char *msg)
{
	time_t	t;

	t = get_mtime();
	printf("%ld %lu %s", t, philo_num, msg);
}
