/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_advanced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:47:42 by plogan            #+#    #+#             */
/*   Updated: 2017/06/16 19:59:31 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_a_weight(t_weight *current, int pos, t_stack **a)
{
	int		stack_size;

	stack_size = measure_stack(a);
	if (pos > stack_size - pos + 1)
		current->rra = stack_size - pos + 1;
	else
		current->ra = pos - 1;
}

void		find_b_weight(t_weight *current, int data, t_stack **b)
{
	t_stack	*head;
	t_stack *first;
	t_stack	*second;
	int		stack_size;

	stack_size = measure_stack(b);
	head = *b;
	first = *b;
	second = first->next;
	current->rb = 1;
	while (second)
	{
		if (data < first->data && data > second->data)
			break ;
		current->rb = current->rb + 1;
		first = first->next;
		second = second->next;
	}
	if (current->rb > stack_size - current->rb)
	{
		current->rrb = stack_size - current->rb;
		current->rb = 0;
	}
	if (!second)
		handle_edge(current, data, b, stack_size);
	current->total = current->ra + current->rra + current->rb +
		current->rrb;
}

void		find_lowest_weight(t_weight *opti, t_stack **a, t_stack **b)
{
	int			a_size;
	int			pos;
	t_weight	temp_w;
	t_stack		*temp_s;

	temp_s = *a;
	init_weight_tab(&temp_w);
	pos = 1;
	find_a_weight(opti, pos, a);
	printf("ra : %d\nrra: %d\n", opti->ra, opti->rra);
	find_b_weight(opti, temp_s->data, b);
	printf("rb : %d\nrrb: %d\n", opti->rb, opti->rrb);
	a_size = measure_stack(a);
	while (temp_s)
	{
		find_a_weight(&temp_w, pos, a);
		find_b_weight(&temp_w, temp_s->data, b);
		if (temp_w.total < opti->total)
		{
			opti->ra = temp_w.ra;
			opti->rra = temp_w.rra;
			opti->rb = temp_w.rb;
			opti->rrb = temp_w.rrb;
			opti->total = temp_w.total;
		}
		temp_s = temp_s->next;
		pos++;
	}
}

void		sort_advanced(t_stack **a, t_stack **b)
{
	int			weight;
	t_weight	opti;

	weight = 0;
	ft_op_pb(a, b, 1);
	ft_op_pb(a, b, 1);
	if ((*b)->data < (*b)->next->data)
		ft_op_rb(a, b, 1);
	while (*a)
	{
		init_weight_tab(&opti);
		find_lowest_weight(&opti, a, b);
		make_moves(&opti, a, b);
	}
	//sort b then
	//fill a 
}
