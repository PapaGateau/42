/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:32:11 by plogan            #+#    #+#             */
/*   Updated: 2017/06/19 18:59:04 by plogan           ###   ########.fr       */
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
	void			(*ft)(t_stack **a, t_stack **b, int usage);
}					t_op;

typedef struct		s_weight
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				total;
}					t_weight;

t_stack				*ft_create_elem(int data);
void				ft_stack_clear(t_stack **begin_stack);
void				ft_stack_push_back(t_stack **begin_stack, int data);
void				init_op_tab(t_op *op_tab);
void				ft_op_sa(t_stack **a, t_stack **b, int usage);
void				ft_op_sb(t_stack **a, t_stack **b, int usage);
void				ft_op_ss(t_stack **a, t_stack **b, int usage);
void				ft_op_pa(t_stack **a, t_stack **b, int usage);
void				ft_op_pb(t_stack **a, t_stack **b, int usage);
void				ft_op_ra(t_stack **a, t_stack **b, int usage);
void				ft_op_rb(t_stack **a, t_stack **b, int usage);
void				ft_op_rr(t_stack **a, t_stack **b, int usage);
void				ft_op_rra(t_stack **a, t_stack **b, int usage);
void				ft_op_rrb(t_stack **a, t_stack **b, int usage);
void				ft_op_rrr(t_stack **a, t_stack **b, int usage);
int					check_args(int argc, char **argv, int arg_i);
void				check_order(t_stack **a, t_stack **b);
int					check_sort(t_stack **a, t_stack **b);
int					measure_stack(t_stack **a);
void				print_stacks(t_stack **a, t_stack **b);
void				sort_select(t_stack **a, t_stack **b);
void				sort_advanced(t_stack **a, t_stack **b);
int					check_a(t_stack **a);
int					check_b(t_stack **b);
int					check_repetition(t_stack **a);
int					find_min(t_stack **stack);
void				init_weight_tab(t_weight *tab);
void				make_moves(t_weight *opti, t_stack **a, t_stack **b);
void				find_a_weight(t_weight *current, int pos, t_stack **a);
void				find_b_weight(t_weight *current, int data, t_stack **b);

#endif
