/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 06:08:24 by plogan            #+#    #+#             */
/*   Updated: 2017/03/17 06:41:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_button(int i, int j, int k)
{
	if (i < j)
	{
		if (k < i)
			return (i);
		else if (j < k)
			return (k);
		else
			return (j);
	}
	else
	{
		if (j > k)
			return (j);
		else if (k > i)
			return (i);
		else
			return (k);
	}
}

int		main(void)
{
	printf("%d", ft_button(100, 50, 1));
}
