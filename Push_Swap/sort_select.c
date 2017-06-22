/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:41:33 by plogan            #+#    #+#             */
/*   Updated: 2017/06/19 16:45:58 by plogan           ###   ########.fr       */
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

int			check_piles(t_stack **a, t_stack **b)
{
	if (check_a(a) && check_b(b))
		return (1);
	return (0);
}

int			check_swap_first(t_stack **a)
{
	int		first;
	int		second;
	t_stack	*temp;

	temp = *a;
	first = temp->data;
	temp = temp->next;
	second = temp->data;
	if (second > first)
		return (0);
	temp = temp->next;
	while (temp)
	{
		if (temp->data < first || temp->data < second)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void		sort_select(t_stack **a, t_stack **b)
{
	int		min;

	while (!check_piles(a, b))
	{
		min = find_min(a);
		if (min && check_swap_first(a))
			ft_op_sa(a, b, 1);
		else
		{
			if (min > measure_stack(a) - min && (min = measure_stack(a) - min))
			{
				while (!check_piles(a, b) && min--)
					ft_op_rra(a, b, 1);
			}
			else
			{
				while (!check_piles(a, b) && min--)
					ft_op_ra(a, b, 1);
			}
		}
		if (!check_piles(a, b))
			ft_op_pb(a, b, 1);
	}
	while (*b)
		ft_op_pa(a, b, 1);
}
