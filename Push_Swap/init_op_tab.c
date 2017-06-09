/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:57:53 by plogan            #+#    #+#             */
/*   Updated: 2017/06/07 15:49:46 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op_tab(t_op *tab)
{
	tab[0].op = "sa";
	tab[0].ft = &ft_op_sa;
	tab[1].op = "sb";
	tab[1].ft = &ft_op_sb;
	tab[2].op = "ss";
	tab[2].ft = &ft_op_ss;
	tab[3].op = "pa";
	tab[3].ft = &ft_op_pa;
	tab[4].op = "pb";
	tab[4].ft = &ft_op_pb;
	tab[5].op = "ra";
	tab[5].ft = &ft_op_ra;
	tab[6].op = "rb";
	tab[6].ft = &ft_op_rb;
	tab[7].op = "rr";
	tab[7].ft = &ft_op_rr;
	tab[8].op = "rra";
	tab[8].ft = &ft_op_rra;
	tab[9].op = "rrb";
	tab[9].ft = &ft_op_rrb;
	tab[10].op = "rrr";
	tab[10].ft = &ft_op_rrr;
}
