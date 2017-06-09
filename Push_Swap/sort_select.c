/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:41:33 by plogan            #+#    #+#             */
/*   Updated: 2017/06/09 14:29:33 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			compare_data(int current, t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (current > temp->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			find_min(t_stack **a)
{
	int		min;
	t_stack	*temp;

	temp = *a;
	min = 0;
	while (temp->next)
	{
		if (compare_data(temp->data, a))
			break ;
		min++;
		temp = temp->next;
	}
	return (min);
}

int			check_piles(t_stack **a, t_stack **b)
{
	if (check_a(a) && check_b(b))
		return (1);
	return (0);
}

void		sort_select(t_stack **a, t_stack **b)
{
	int		min;

	while (!check_piles(a, b))
	{
		min = find_min(a);
		if (min > get_stack_size(a) - min)
		{
			min = get_stack_size(a) - min;
			while (!check_piles(a, b) && min--)
				ft_op_rra(a, b, 1);
		}
		else
		{
			while (!check_piles(a, b) && min--)
				ft_op_ra(a, b, 1);
		}
		if (!check_piles(a, b))
			ft_op_pb(a, b, 1);
	}
	while (*b)
		ft_op_pa(a, b, 1);
}
