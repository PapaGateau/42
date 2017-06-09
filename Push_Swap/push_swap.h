/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:32:11 by plogan            #+#    #+#             */
/*   Updated: 2017/06/08 18:13:53 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_stack
{
	intmax_t		data;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_op
{
	char			*op;
	void			(*ft)(t_stack **a, t_stack **b);
}					t_op;

t_stack				*ft_create_elem(int data);
void				ft_stack_clear(t_stack **begin_stack);
void				ft_stack_push_back(t_stack **begin_stack, int data);
void				init_op_tab(t_op *op_tab);
void				ft_op_sa(t_stack **a, t_stack **b);
void				ft_op_sb(t_stack **a, t_stack **b);
void				ft_op_ss(t_stack **a, t_stack **b);
void				ft_op_pa(t_stack **a, t_stack **b);
void				ft_op_pb(t_stack **a, t_stack **b);
void				ft_op_ra(t_stack **a, t_stack **b);
void				ft_op_rb(t_stack **a, t_stack **b);
void				ft_op_rr(t_stack **a, t_stack **b);
void				ft_op_rra(t_stack **a, t_stack **b);
void				ft_op_rrb(t_stack **a, t_stack **b);
void				ft_op_rrr(t_stack **a, t_stack **b);
int					check_args(int argc, char **argv);
void				check_order(t_stack **a, t_stack **b);
int					check_sort(t_stack **a, t_stack **b);
int					get_stack_size(t_stack **a);
void				print_stacks(t_stack **a, t_stack **b);
void				sort_select(t_stack **a, t_stack **b);
int					check_a(t_stack **a);
int					check_b(t_stack **b);

#endif
