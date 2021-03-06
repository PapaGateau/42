/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:30:33 by fbonnin           #+#    #+#             */
/*   Updated: 2017/04/20 17:05:47 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr(int n)
{
	int p10;

	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	p10 = 1;
	while (n / p10 > 9)
		p10 *= 10;
	while (p10 > 0)
	{
		ft_putchar(n / p10 + 48);
		n %= p10;
		p10 /= 10;
	}
}
