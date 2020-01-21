# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:14:56 by plogan            #+#    #+#              #
#    Updated: 2020/01/21 18:33:54 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR= src/
SRC= ft_bzero.s ft_cat.s ft_isalnum.s ft_isalpha.s ft_isascii.s \
	ft_isdigit.s ft_islower.s ft_isprint.s ft_isupper.s ft_memcpy.s ft_memset.s \
	ft_puts.s ft_strcat.s ft_strdup.s ft_strlen.s ft_tolower.s ft_toupper.s

OBJ_DIR= obj/
OBJ= $(patsubst %.s, $(OBJ_DIR)/%.o, $(SRC))

LIB_NAME= libfts.a

CC= nasm
CC_FLAGS= -f macho64

.PHONY: all

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "$(LIB_NAME) done"

$(OBJ_DIR)/%.o: $(addprefix $(SRC_DIR),%.s)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CC_FLAGS) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm $(LIB_NAME)

re: fclean $(LIB_NAME)
