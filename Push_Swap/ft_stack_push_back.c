/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:21:21 by plogan            #+#    #+#             */
/*   Updated: 2017/06/07 19:16:33 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push_back(t_stack **begin_stack, int data)
{
	t_stack	*new;

	if (begin_stack == NULL)
		return ;
	if (*begin_stack == NULL)
	{
		*begin_stack = ft_create_elem(data);
		return ;
	}
	new = *begin_stack;
	while (new->next != NULL)
	{
		new = new->next;
	}
	new->next = ft_create_elem(data);
}
