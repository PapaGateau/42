/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:28:54 by plogan            #+#    #+#             */
/*   Updated: 2017/06/13 15:39:48 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	input_moves(t_stack **a, t_stack **b, int fd, int usage)
{
	char	*line;
	int		struct_index;
	t_op	op_tab[11];

	init_op_tab(&*op_tab);
	if (usage)
		print_stacks(a, b);
	while ((get_next_line(fd, &line) > 0) && !(struct_index = 0))
	{
		while (struct_index < 11)
		{
			if (!ft_strcmp(line, op_tab[struct_index].op))
			{
				op_tab[struct_index].ft(a, b, usage);
				break ;
			}
			struct_index++;
		}
		if (struct_index == 11)
			return (0);
		free(line);
	}
	free(line);
	check_order(a, b);
	return (1);
}

static int	fill_a(t_stack **a, char *arg)
{
	int		index;

	index = 0;
	while (arg[index])
	{
		while (arg[index] == ' ')
			index++;
		if (ft_atoi(&arg[index]) > INT_MAX || ft_atoi(&arg[index]) < INT_MIN)
			return (0);
		ft_stack_push_back(a, ft_atoi(&arg[index]));
		while (arg[index] && arg[index] != ' ')
			index++;
		while (arg[index] && arg[index] == ' ')
			index++;
	}
	if (!check_repetition(a))
		return (0);
	return (1);
}

static int	convert_args(int fd, int usage, int argc, char **argv)
{
	int		index;
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	index = 1;
	if (usage)
		index++;
	if (fd)
		index++;
	if (!check_args(argc, argv, index))
		return (0);
	while (index < argc)
	{
		if (!fill_a(&a, argv[index]))
			return (0);
		index++;
	}
	if (!input_moves(&a, &b, fd, usage))
		return (0);
	ft_stack_clear(&a);
	ft_stack_clear(&a);
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		index;
	int		usage;

	usage = 0;
	index = 1;
	if (argc < 2)
		return (0);
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		usage = 2;
		index++;
	}
	if ((fd = open(argv[index], O_RDONLY)) == -1)
		fd = 0;
	else
		index++;
	if (argc < 1 + index)
	{
		write(1, "usage: ./checker [-v] [filename] [values...]\n", 45);
		return (0);
	}
	if (!convert_args(fd, usage, argc, argv))
		write(2, "Error\n", 6);
	return (0);
}
