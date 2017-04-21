# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 17:08:01 by plogan            #+#    #+#              #
#    Updated: 2017/03/27 18:02:55 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRC_C = main.c \
		ft_putnbr.c \
		calc.c \
		ft_atoi.c

SRC_O = main.o \
		ft_putnbr.o \
		calc.o \
		ft_atoi.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC_C)
	gcc -o $(NAME) $(SRC_O)

clean:
	/bin/rm -f $(SRC_O)
