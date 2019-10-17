# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:14:56 by plogan            #+#    #+#              #
#    Updated: 2019/10/17 15:35:10 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR_ASM= src/asm
SRC_ASM= ft_isascii.s

OBJ_DIR_ASM= obj/asm
OBJ_ASM= $(patsubst %.c, $(OBJ_DIR_ASM)/%.o, $(SRC_ASM))

LIB_NAME= libfts.a

CC_ASM= nasm
CC_FLAGS_ASM= -f macho64

.PHONY: all

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_ASM)
	ar rcs $@ $^
	@echo "$(LIB_NAME) made"

$(OBJ_DIR_ASM)/%.o: $(SRC_DIR_ASM)/%.s
	@mkdir $(SRC_DIR_ASM)
	$(CC_ASM) $(CC_FLAGS_ASM) $< -o $@

clean:
	@rm -rf $(OBJ_DIR_ASM)

fclean: clean
	@rm $(LIB_NAME)

re: fclean $(LIB_NAME)
