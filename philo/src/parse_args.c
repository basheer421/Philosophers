/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:30:20 by bammar            #+#    #+#             */
/*   Updated: 2023/02/04 15:39:04 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_contains_nonnum(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if ((str[i] < '0' || str[i] > '9')
			&& str[i] != '+')
			return (1);
	return (0);
}

static int	set_words(int argc, char **argv, char **words)
{
	int		wordc;

	wordc = -1;
	while (++wordc < argc - 1)
	{
		words[wordc] = ft_skip_spaces(argv[wordc + 1]);
		if (ft_contains_nonnum(words[wordc]))
			return (0);
	}
	return (1);
}

static int	is_valid_num(char *s, size_t n)
{
	if (!s)
		return (1);
	if (n == 0 && (*s >= '0' && *s <= '9')
		&& ft_strlen(s) == 1 && *s == '0')
		return (1);
	else if (n == 0)
		return (0);
	return (1);
}

int	fill_philo_args(int argc, char **argv, t_philo_args *args)
{
	char	*words[5];
	int		i;

	i = -1;
	while (++i < 5)
		words[i] = NULL;
	
	memset(args, 0, sizeof(t_philo_args));
	if (argc == 6)
		args->is_limited = true;
	if (!set_words(argc, argv, words))
		return (0);
	args->count = ft_atol(words[0]);
	args->die_time = ft_atol(words[1]);
	args->eat_time = ft_atol(words[2]);
	args->sleep_time = ft_atol(words[3]);
	if (args->is_limited)
		args->eat_limit = ft_atol(words[4]);
	if (!is_valid_num(words[0], args->count)
		||	!is_valid_num(words[1], args->die_time)
		||  !is_valid_num(words[2], args->eat_time)
		||  !is_valid_num(words[3], args->sleep_time)
		||  !is_valid_num(words[4], args->eat_limit))
		return (0);
	return (1);
}
