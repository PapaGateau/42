/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:27:02 by plogan            #+#    #+#             */
/*   Updated: 2017/06/08 17:02:41 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		select_sort(t_stack **a, t_stack **b, int fd, int argc)
{
	int		stack_size;

	(void)fd;
	(void)argc;
	if (check_sort(a, b))
		return ;
	stack_size = get_stack_size(a);
//	if (stack_size < 7)
		sort_select(a, b);
}

int         main(int argc, char **argv)
{
	int     arg_index;
	int     fd;
	t_stack *a;
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
	select_sort(&a, &b, fd, argc);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}
