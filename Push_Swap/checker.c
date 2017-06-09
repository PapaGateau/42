/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:28:54 by plogan            #+#    #+#             */
/*   Updated: 2017/06/09 14:17:12 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	input_moves(t_stack **a, t_stack **b, int fd)
{
	int		ret;
	char	*line;
	int		struct_index;
	t_op	op_tab[11];

	init_op_tab(&*op_tab);
	line = NULL;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		struct_index = 0;
		while (struct_index < 11)
		{
			if (!ft_strcmp(line, op_tab[struct_index].op))
			{
				op_tab[struct_index].ft(a, b, 0);
				break ;
			}
			struct_index++;
		}
		if (struct_index == 11)
			return (0);
	}
	check_order(a, b);
	return (1);
}

int			main(int argc, char **argv)
{
	int		arg_index;
	int		fd;
	t_stack	*a;
	t_stack *b;

	b = NULL;
	fd = 0;
	if (!check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	arg_index = 1;
	if (argc < 2)
		return (0);
	while (arg_index < argc)
	{
		ft_stack_push_back(&a, ft_atoi(argv[arg_index]));
		arg_index++;
	}
	if (!input_moves(&a, &b, fd))
		write(2, "Error\n", 6);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}
