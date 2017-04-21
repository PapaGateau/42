/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 09:47:51 by plogan            #+#    #+#             */
/*   Updated: 2017/03/15 16:04:55 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
	long nbl;

	nbl = nb;
	if (nbl < 0)
	{
		ft_putchar('-');
		nbl = nbl * -1;
	}
	ft_indiv(nbl);
}
