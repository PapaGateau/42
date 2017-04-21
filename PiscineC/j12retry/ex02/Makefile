# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 19:49:01 by plogan            #+#    #+#              #
#    Updated: 2017/03/29 23:19:33 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

SRC_C = main.c \
		string.c \
		ft_atoi.c \
		ft_buffer.c

SRC_O = main.o \
		string.o \
		ft_atoi.o \
		ft_buffer.o

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC_C)
	gcc -c $(SRC_C)

clean :
	rm -f $(SRC_O)

fclean : clean
	rm -f $(NAME)

re : fclean all
