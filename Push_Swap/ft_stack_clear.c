/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:32:20 by plogan            #+#    #+#             */
/*   Updated: 2017/06/07 19:35:45 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_clear(t_stack **begin_stack)
{
	t_stack	*point;
	t_stack	*remove;

	if (begin_stack == NULL)
		return ;
	if (*begin_stack == NULL)
		return ;
	point = *begin_stack;
	while (point->next != NULL)
	{
		remove = point;
		point = point->next;
		free(remove);
	}
	free(point);
	*begin_stack = NULL;
}
