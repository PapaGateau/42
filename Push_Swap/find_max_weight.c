/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_edge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:25:08 by plogan            #+#    #+#             */
/*   Updated: 2017/06/16 19:59:28 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int         check_if_superior(int data, t_stack **b)
{
	t_stack *temp;

	temp = *b;
	while (temp)
	{
		if (temp->data > data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void		handle_edge(t_weight *current, int data, t_stack **b, int size)
{
	// change algorithm from comparing over/under to:
	// seek out closest under, insert above
	// iter in stack, while saving smallest difference with inferior values only
	// lowest difference represents the closest under
}
