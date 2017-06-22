/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:27:02 by plogan            #+#    #+#             */
/*   Updated: 2017/06/19 18:28:53 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	call_sort(t_stack **a, t_stack **b)
{
	int		stack_size;

	stack_size = measure_stack(a);
	if (check_sort(a, b))
		return ;
	if (stack_size > 10)
		sort_advanced(a, b);
	else
	{
		if (stack_size == 3 && (*a)->next->next->data < (*a)->data &&
				(*a)->next->next->data < (*a)->next->data &&
				(*a)->data > (*a)->next->data)
			ft_op_sa(a, b, 1);
		sort_select(a, b);
	}
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

static int	convert_args(t_stack **a, int argc, char **argv)
{
	int		index;

	index = 1;
	while (index < argc)
	{
		if (!fill_a(a, argv[index]))
			return (0);
		index++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!convert_args(&a, argc, argv))
	{
		write(2, "Error\n", 6);
		ft_stack_clear(&a);
		return (0);
	}
	call_sort(&a, &b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}
