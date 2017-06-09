/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:42:19 by plogan            #+#    #+#             */
/*   Updated: 2017/06/07 18:41:36 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_order(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (*b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	first = *a;
	second = (*a)->next;
	while (second)
	{
		if (first->data > second->data)
		{
			write(1, "KO\n", 3);
			return ;
		}
		first = first->next;
		second = second->next;
	}
	write(1, "OK\n", 3);
}
