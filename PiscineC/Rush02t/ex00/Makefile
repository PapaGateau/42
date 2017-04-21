# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/19 20:14:23 by gduron            #+#    #+#              #
#    Updated: 2017/03/27 00:26:22 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

SRC = \
srcs/ft_strcat.c \
srcs/ft_putnbr.c \
srcs/ft_putchar.c \
srcs/ft_putstr.c \
srcs/ft_strcmp.c \
srcs/ft_strlen.c \
srcs/ft_strjoin.c \
srcs/get_input.c \
srcs/find_colle.c \
srcs/rush00.c \
srcs/rush01.c \
srcs/rush02.c \
srcs/rush03.c \
srcs/rush04.c \
srcs/main.c

OBJ = $(SRC:.c=.o)

HEADER = includes

all: $(NAME)

$(NAME): $(SRC)
	@gcc -o $(NAME) $(SRC) -I $(HEADER)
	@echo "Compilation:\033[92m OK\033[0m"

clean:
	@echo "Deleting:\033[33m $(NAME)"
	@rm $(NAME)

fclean: clean
