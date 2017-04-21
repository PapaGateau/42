/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 10:51:47 by plogan            #+#    #+#             */
/*   Updated: 2017/03/27 18:03:18 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H
# include <unistd.h>

int				ft_atoi(char *str);
void			ft_putnbr(int nb);
int				ft_add(int n1, int n2);
int				ft_sub(int n1, int n2);
int				ft_mul(int n1, int n2);
int				ft_div(int n1, int n2);
int				ft_mod(int n1, int n2);

typedef struct	s_doop
{
	char	op;
	int		(*ft)(int, int);
}				t_doop;

t_doop g_opptab[] =
{
	{'+', &ft_add},
	{'-', &ft_sub},
	{'*', &ft_mul},
	{'/', &ft_div},
	{'%', &ft_mod}
};

#endif
