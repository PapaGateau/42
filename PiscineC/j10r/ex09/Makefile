# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/25 18:14:06 by plogan            #+#    #+#              #
#    Updated: 2017/03/27 18:21:08 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op

SRC_C = ft_add.c \
		ft_div.c \
		ft_mul.c \
		ft_putnbr.c \
		ft_usage.c \
		ft_check_op.c \
		ft_mod.c \
		ft_sub.c \
		main.c \
		ft_atoi.c

SRC_O = ft_add.o \
		ft_div.o \
		ft_mul.o \
		ft_putnbr.o \
		ft_usage.o \
		ft_check_op.o \
		ft_mod.o \
		ft_sub.o \
		main.o \
		ft_atoi.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC_C)
	gcc -o $(NAME) $(SRC_O)

clean:
	/bin/rm -f $(SRC_O)
