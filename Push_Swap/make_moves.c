/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:52:16 by plogan            #+#    #+#             */
/*   Updated: 2017/06/19 18:36:25 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	perform_rr(t_weight **opti, t_stack **a, t_stack **b)
{
	while ((*opti)->ra && (*opti)->rb)
	{
		ft_op_rr(a, b, 1);
		(*opti)->ra--;
		(*opti)->rb--;
	}
}

static void	perform_rrr(t_weight **opti, t_stack **a, t_stack **b)
{
	while ((*opti)->rra && (*opti)->rrb)
	{
		ft_op_rrr(a, b, 1);
		(*opti)->rra--;
		(*opti)->rrb--;
	}
}

void		make_moves(t_weight *opti, t_stack **a, t_stack **b)
{
	if (opti->ra && opti->rb)
		perform_rr(&opti, a, b);
	if (opti->rra && opti->rrb)
		perform_rrr(&opti, a, b);
	while (opti->ra--)
		ft_op_ra(a, b, 1);
	while (opti->rb--)
		ft_op_rb(a, b, 1);
	while (opti->rra--)
		ft_op_rra(a, b, 1);
	while (opti->rrb--)
		ft_op_rrb(a, b, 1);
	ft_op_pb(a, b, 1);
}
