/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repetition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:59:31 by plogan            #+#    #+#             */
/*   Updated: 2017/06/12 20:04:18 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_repetition(t_stack **a)
{
	int		temp_index;
	int		current_index;
	t_stack *temp;
	t_stack	*current;

	current_index = 1;
	current = *a;
	while (current)
	{
		temp = *a;
		temp_index = 1;
		while (temp->next)
		{
			if (current_index != temp_index && temp->data == current->data)
				return (0);
			temp_index++;
			temp = temp->next;
		}
		current = current->next;
		current_index++;
	}
	return (1);
}
