/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:05:00 by plogan            #+#    #+#             */
/*   Updated: 2017/03/15 15:19:34 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	if (power != 1)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	else
	{
		return (nb);
	}
}

int		main(void)
{
	printf("%d", ft_recursive_power(4, 3));
	return(0);
}
