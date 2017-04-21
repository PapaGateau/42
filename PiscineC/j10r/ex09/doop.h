/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:34:54 by plogan            #+#    #+#             */
/*   Updated: 2017/03/27 18:18:39 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H
# include <unistd.h>

typedef struct	s_opp
{
	char	*op;
	int		(*ft)(int, int);
}				t_opp;

int				ft_atoi(char *str);
int				ft_check_op(char *op);
void			ft_putnbr(int nb);
int				ft_add(int n1, int n2);
int				ft_sub(int n1, int n2);
int				ft_mul(int n1, int n2);
int				ft_div(int n1, int n2);
int				ft_mod(int n1, int n2);
int				ft_usage(int n1, int n2);
int				ft_check_op(char *op);

#endif
