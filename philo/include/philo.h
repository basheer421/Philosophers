/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:56:30 by bammar            #+#    #+#             */
/*   Updated: 2023/02/04 15:38:42 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <string.h>

/*
	size_t:
	count;
	die_time;
	eat_time;
	sleep_time;
	eat_limit;
	is_limited -> bool

	Eat limit is set to -1 when it's not given.
*/
typedef struct s_philo_args
{
	size_t	count;
	size_t	die_time;
	size_t	eat_time;
	size_t	sleep_time;
	size_t	eat_limit;
	bool	is_limited;
}	t_philo_args;

long	ft_atol(const char *str);
char	*ft_skip_spaces(char *str);
int 	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_index(const char *str, int c);
int		fill_philo_args(int argc, char **argv, t_philo_args *args);

#endif