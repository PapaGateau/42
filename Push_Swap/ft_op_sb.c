/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:13:07 by plogan            #+#    #+#             */
/*   Updated: 2017/06/12 17:19:34 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_op_sb(t_stack **a, t_stack **b, int usage)
{
	t_stack *second;

	(void)*a;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	second = (*b)->next;
	(*b)->next = second->next;
	second->next = *b;
	*b = second;
	if (usage)
		write(1, "sb\n", 3);
	if (usage == 2)
		print_stacks(a, b);
}
