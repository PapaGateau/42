/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:10:04 by plogan            #+#    #+#             */
/*   Updated: 2017/06/08 18:12:14 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_a(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!*a)
		return (1);
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
