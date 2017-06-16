/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:27:33 by plogan            #+#    #+#             */
/*   Updated: 2017/06/12 17:18:17 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_op_rra(t_stack **a, t_stack **b, int usage)
{
	t_stack	*temp_start;
	t_stack	*temp_end;

	(void)*b;
	if (!*a || !(*a)->next)
		return ;
	temp_start = (*a)->next;
	temp_end = *a;
	while (temp_start->next)
	{
		temp_start = temp_start->next;
		temp_end = temp_end->next;
	}
	temp_start->next = *a;
	temp_end->next = NULL;
	*a = temp_start;
	if (usage)
		write(1, "rra\n", 4);
	if (usage == 2)
		print_stacks(a, b);
}
