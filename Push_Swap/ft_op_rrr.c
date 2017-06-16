/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:39:40 by plogan            #+#    #+#             */
/*   Updated: 2017/06/12 17:19:02 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_op_rrr(t_stack **a, t_stack **b, int usage)
{
	ft_op_rra(a, b, 0);
	ft_op_rrb(a, b, 0);
	if (usage)
		write(1, "rrr\n", 4);
	if (usage == 2)
		print_stacks(a, b);
}
