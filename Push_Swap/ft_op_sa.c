/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_sa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:46:55 by plogan            #+#    #+#             */
/*   Updated: 2017/06/12 17:19:17 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_op_sa(t_stack **a, t_stack **b, int usage)
{
	t_stack *second;

	(void)*b;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
	if (usage)
		write(1, "sa\n", 3);
	if (usage == 2)
		print_stacks(a, b);
}
