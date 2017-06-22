/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_a_weight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 18:52:32 by plogan            #+#    #+#             */
/*   Updated: 2017/06/19 18:55:34 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_a_weight(t_weight *current, int pos, t_stack **a)
{
	int	stack_size;

	stack_size = measure_stack(a);
	if (pos > stack_size - pos)
	{
		current->rra = stack_size - pos + 1;
		current->ra = 0;
	}
	else
	{
		current->ra = pos - 1;
		current->rra = 0;
	}
}
