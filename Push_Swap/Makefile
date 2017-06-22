# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plogan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/12 14:59:42 by plogan            #+#    #+#              #
#    Updated: 2017/06/19 18:59:01 by plogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

SRC_NAME = checker.c check_a.c check_b.c check_args.c check_order.c \
		   check_sort.c ft_create_elem.c ft_op_pa.c ft_op_pb.c ft_op_ra.c \
		   ft_op_rb.c ft_op_rr.c ft_op_rra.c ft_op_rrb.c ft_op_rrr.c \
		   ft_op_sa.c ft_op_sb.c ft_op_ss.c ft_stack_clear.c \
		   measure_stack.c init_op_tab.c print_stacks.c sort_select.c \
		   ft_stack_push_back.c check_repetition.c sort_advanced.c \
		   find_min.c init_weight_tab.c make_moves.c find_a_weight.c \
		   find_b_weight.c

SRC_NAME2 = push_swap.c check_a.c check_b.c check_args.c check_order.c \
		   check_sort.c ft_create_elem.c ft_op_pa.c ft_op_pb.c ft_op_ra.c \
		   ft_op_rb.c ft_op_rr.c ft_op_rra.c ft_op_rrb.c ft_op_rrr.c \
		   ft_op_sa.c ft_op_sb.c ft_op_ss.c ft_stack_clear.c \
		   measure_stack.c init_op_tab.c print_stacks.c sort_select.c \
		   ft_stack_push_back.c check_repetition.c sort_advanced.c \
		   find_min.c init_weight_tab.c make_moves.c find_a_weight.c \
		   find_b_weight.c

OFILES = $(SRC_NAME:.c=.o)
OFILES2 = $(SRC_NAME2:.c=.o)

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

all: makelibs $(NAME1) $(NAME2)

makelibs:
	@make -C Libft

$(NAME1): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) Libft/libft.a \
		Libft/my_printf/libftprintf.a -o $(NAME1)
	@echo "Compilation checker:\033[92m OK\033[0m"

$(NAME2): $(OFILES2)
	$(CC) $(CFLAGS) $(OFILES2) Libft/libft.a \
		Libft/my_printf/libftprintf.a -o $(NAME2)
	@echo "Compilation push_swap:\033[92m OK\033[0m"

%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I includes

clean:
	@make -C Libft clean
	@rm -rf $(OFILES) $(OFILES2)
	@echo "Deleting:\n\033[33m $(OFILES)\033[0m"

fclean: clean
	@make -C Libft fclean
	@rm -rf $(NAME1) $(NAME2)
	@echo "Deleting:\033[33m $(NAME1) $(NAME2)\033[0m"

re : fclean all

.PHONY: all clean fclean re
