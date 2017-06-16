/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rrb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:37:52 by plogan            #+#    #+#             */
/*   Updated: 2017/06/12 17:34:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_op_rrb(t_stack **a, t_stack **b, int usage)
{
	t_stack *temp_start;
	t_stack	*temp_end;

	(void)*a;
	if (!*b || !(*b)->next)
		return ;
	temp_start = (*b)->next;
	temp_end = *b;
	while (temp_start->next)
	{
		temp_start = temp_start->next;
		temp_end = temp_end->next;
	}
	temp_start->next = *b;
	temp_end->next = NULL;
	*b = temp_start;
	if (usage)
		write(1, "rrb\n", 4);
	if (usage == 2)
		print_stacks(a, b);
}
