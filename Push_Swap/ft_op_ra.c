/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_ra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:09:12 by plogan            #+#    #+#             */
/*   Updated: 2017/06/12 17:16:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_op_ra(t_stack **a, t_stack **b, int usage)
{
	t_stack *temp_start;
	t_stack *temp_end;

	(void)*b;
	if (!*a || !(*a)->next)
		return ;
	temp_start = (*a)->next;
	temp_end = *a;
	while (temp_end->next)
		temp_end = temp_end->next;
	temp_end->next = *a;
	(*a)->next = NULL;
	*a = temp_start;
	if (usage)
		write(1, "ra\n", 3);
	if (usage == 2)
		print_stacks(a, b);
}
