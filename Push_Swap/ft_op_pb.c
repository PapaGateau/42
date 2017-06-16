/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:30:34 by plogan            #+#    #+#             */
/*   Updated: 2017/06/12 17:16:32 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_op_pb(t_stack **a, t_stack **b, int usage)
{
	t_stack *temp;

	if (!*a)
		return ;
	if (!*b)
	{
		*b = *a;
		*a = (*a)->next;
		(*b)->next = NULL;
	}
	else
	{
		temp = *b;
		*b = *a;
		*a = (*a)->next;
		(*b)->next = temp;
	}
	if (usage)
		write(1, "pb\n", 3);
	if (usage == 2)
		print_stacks(a, b);
}
