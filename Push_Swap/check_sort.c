/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:00:00 by plogan            #+#    #+#             */
/*   Updated: 2017/06/08 18:13:55 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort(t_stack **a, t_stack **b)
{
	t_stack *first;
	t_stack *second;

	if (*b)
		return (0);
	first = *a;
	second = (*a)->next;
	while (second)
	{
		if (first->data > second->data)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}
