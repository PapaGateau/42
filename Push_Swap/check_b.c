/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:12:22 by plogan            #+#    #+#             */
/*   Updated: 2017/06/08 18:13:35 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_b(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!*b)
		return (1);
	first = *b;
	second = (*b)->next;
	while (second)
	{
		if (first->data < second->data)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}
