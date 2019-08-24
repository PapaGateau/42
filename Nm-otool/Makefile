# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 13:10:03 by peterlog          #+#    #+#              #
#    Updated: 2019/08/24 15:10:06 by peterlogan       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = nm/nm_tools.c otool/hexdump.c shared/access_file.c shared/macho_handler.c
SRC += shared/utils.c
SRC_NM = ft_nm.c $(SRC)
SRC_OTOOL = $(SRC)

OBJ_NM = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_NM))
OBJ_OTOOL = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_OTOOL))

LIBS = Libft/libft.a Libft/my_printf/libftprintf.a

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

NAME = ft_nm_otool
NAME_NM = ft_nm
NAME_OTOOL = ft_otool

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all

all: makelibs $(NAME)

makelibs:
	@make -C Libft

$(NAME): $(NAME_NM) $(NAME_OTOOL)

$(NAME_NM): makelibs $(OBJ_NM)
	@$(CC) -o $@ $(LIBS) $(OBJ_NM)
	@echo "Executable:\033[92m OK\033[0m"

$(NAME_OTOOL): makelibs $(OBJ_OTOOL)
	@$(CC) -o $@ $(LIBS) $(OBJ_OTOOL)
	@echo "Executable:\033[92m OK\033[0m"

$(OBJ_DIR)/%.o: $(addprefix $(SRC_DIR)/,%.c)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/nm
	@mkdir -p $(OBJ_DIR)/otool
	@mkdir -p $(OBJ_DIR)/shared
	@$(CC) -c $^ $(CFLAGS) -o $@

clean:
	@make -C Libft clean
	@rm -rf $(OBJ_DIR)
	@echo "Deleting:\033[33m object files\033[0m"

fclean: clean
	@make -C Libft fclean
	@rm -f $(NAME) $(NAME_NM) $(NAME_OTOOL)

re: fclean $(NAME)
