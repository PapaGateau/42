/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:36:20 by plogan            #+#    #+#             */
/*   Updated: 2017/06/12 20:08:12 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		measure_stack(t_stack **a)
{
	int		size;
	t_stack	*temp;

	if (!*a)
		return (0);
	size = 1;
	temp = *a;
	while (temp->next)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
