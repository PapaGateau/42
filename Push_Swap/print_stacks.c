/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:05:29 by plogan            #+#    #+#             */
/*   Updated: 2017/06/07 19:31:01 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_a_b(t_stack **temp_a, t_stack **temp_b)
{
	ft_printf("|                        |\n");
	ft_printf("|%4d             %4d   |\n", (*temp_a)->data, (*temp_b)->data);
	ft_printf("|________________________|\n");
	*temp_a = (*temp_a)->next;
	*temp_b = (*temp_b)->next;
}

static void	print_a(t_stack **temp_a)
{
	ft_printf("|                        |\n");
	ft_printf("|%4d                    |\n", (*temp_a)->data);
	ft_printf("|________________________|\n");
	*temp_a = (*temp_a)->next;
}

static void	print_b(t_stack **temp_b)
{
	ft_printf("|                        |\n");
	ft_printf("|                 %4d   |\n", (*temp_b)->data);
	ft_printf("|________________________|\n");
	*temp_b = (*temp_b)->next;
}

void		print_stacks(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack *temp_b;

	temp_a = *a;
	temp_b = *b;
	ft_printf("=== a === STACKS === b ===\n");
	while (temp_a || temp_b)
	{
		if (temp_a && temp_b)
			print_a_b(&temp_a, &temp_b);
		if (temp_a && !temp_b)
			print_a(&temp_a);
		if (!temp_a && temp_b)
			print_b(&temp_b);
	}
}
