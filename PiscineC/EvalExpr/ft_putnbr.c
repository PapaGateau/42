/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:27:25 by plogan            #+#    #+#             */
/*   Updated: 2017/03/25 13:31:23 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"

void	ft_indiv(long nb)
{
	int		p;
	long	cpy;

	p = 1;
	cpy = nb;
	while (cpy >= 10)
	{
		p = p * 10;
		cpy = cpy / 10;
	}
	while (p >= 1)
	{
		ft_putchar((nb / p) + '0');
		nb = nb % p;
		p = p / 10;
	}
}

void	ft_putnbr(int nb)
{
	long	nbl;

	nbl = nb;
	if (nbl < 0)
	{
		ft_putchar('-');
		nbl = nbl * -1;
	}
	ft_indiv(nbl);
}
