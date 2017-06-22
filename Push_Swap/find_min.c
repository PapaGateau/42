/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:28:23 by plogan            #+#    #+#             */
/*   Updated: 2017/06/19 18:45:09 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare_data(int current, t_stack **a)
{
	t_stack *temp;

	temp = *a;
	while (temp)
	{
		if (current > temp->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			find_min(t_stack **a)
{
	int		min;
	t_stack	*temp;

	temp = *a;
	min = 0;
	while (temp)
	{
		if (compare_data(temp->data, a))
			break ;
		min++;
		temp = temp->next;
	}
	return (min);
}
