# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 21:59:12 by bammar            #+#    #+#              #
#    Updated: 2023/02/01 01:52:21 by bammar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

FILES	=	src/philo.c \
			src/ft_atol.c \
			src/ft_str_utils.c \
			src/parse_args.c \

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra  -I ./include -g -fsanitize=address

LINKS	=	-pthread

OBJS	=	$(FILES:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(LINKS) -o $(NAME)

clean:
	$(RM) -f $(OBJS)

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
