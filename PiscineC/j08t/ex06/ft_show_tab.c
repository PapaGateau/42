/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:25:54 by plogan            #+#    #+#             */
/*   Updated: 2017/03/22 16:09:58 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_indiv(long nbl, long cpy, int p)
{
	while (cpy >= 10)
	{
		p = p * 10;
		cpy = cpy / 10;
	}
	while (p >= 1)
	{
		ft_putchar((nbl / p) + '0');
		nbl = nbl % p;
		p = p / 10;
	}
}

void	ft_putnbr(int nbr)
{
	long	nbl;
	long	cpy;
	int		p;

	p = 1;
	nbl = nbr;
	cpy = nbl;
	ft_indiv(nbl, cpy, p);
}

void	ft_show_tab(struct s_stock_par *par)
{
	int		j;
	int		k;

	j = 0;
	while (par[j].str != '\0')
	{
		ft_putstr(par[j].str);
		ft_putchar('\n');
		ft_putnbr(par[j].size_param);
		ft_putchar('\n');
		k = 0;
		while (par[j].tab[k] != '\0')
		{
			ft_putstr(par[j].tab[k]);
			ft_putchar('\n');
			k++;
		}
		j++;
	}
}
