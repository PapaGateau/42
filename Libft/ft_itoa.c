/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:31:03 by plogan            #+#    #+#             */
/*   Updated: 2017/04/14 13:12:26 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_size(int n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_unit(char *str, long nb, int is_neg)
{
	int		i;
	int		p;
	long	cpy;

	i = 0;
	p = 1;
	cpy = nb;
	while (cpy >= 10)
	{
		p = p * 10;
		cpy = cpy / 10;
	}
	if (is_neg == 1)
		str[i++] = '-';
	while (p >= 1)
	{
		str[i] = (nb / p) + '0';
		i++;
		nb = nb % p;
		p = p / 10;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	long	nbl;
	char	*str;
	int		is_neg;

	is_neg = 0;
	nbl = n;
	if (nbl < 0)
	{
		is_neg = 1;
		nbl = nbl * -1;
	}
	str = (char *)malloc(sizeof(char) * (int_size(nbl) + is_neg + 1));
	if (str == NULL)
		return (0);
	return (ft_unit(str, nbl, is_neg));
}
