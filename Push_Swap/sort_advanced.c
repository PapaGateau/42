/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_advanced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:47:42 by plogan            #+#    #+#             */
/*   Updated: 2017/06/19 19:07:43 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		refresh_opti(t_weight *opti, t_weight *temp_w)
{
	opti->ra = temp_w->ra;
	opti->rra = temp_w->rra;
	opti->rb = temp_w->rb;
	opti->rrb = temp_w->rrb;
	opti->total = temp_w->total;
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
	find_b_weight(opti, temp_s->data, b);
	a_size = measure_stack(a);
	while (temp_s)
	{
		find_a_weight(&temp_w, pos, a);
		find_b_weight(&temp_w, temp_s->data, b);
		if (temp_w.total < opti->total)
			refresh_opti(opti, &temp_w);
		temp_s = temp_s->next;
		pos++;
	}
}

static void	fill_a(int b_size, t_stack **a, t_stack **b)
{
	int		min;

	min = find_min(b);
	if (b_size - min > min)
	{
		while (min + 1)
		{
			ft_op_rb(a, b, 1);
			min--;
		}
	}
	else
	{
		while (min < b_size - 1)
		{
			ft_op_rrb(a, b, 1);
			min++;
		}
	}
	while (*b)
		ft_op_pa(a, b, 1);
}

void		sort_advanced(t_stack **a, t_stack **b)
{
	int			b_size;
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
	b_size = measure_stack(b);
	fill_a(b_size, a, b);
}
