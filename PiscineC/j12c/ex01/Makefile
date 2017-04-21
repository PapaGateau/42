# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 19:39:45 by plogan            #+#    #+#              #
#    Updated: 2017/03/29 23:19:16 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

SRC = main.c

OFILES = main.o

all : $(NAME)

$(NAME) :
	gcc -c $(SRC)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all
