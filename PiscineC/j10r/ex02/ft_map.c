/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:18:54 by plogan            #+#    #+#             */
/*   Updated: 2017/03/27 17:16:25 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*out;
	int		i;

	i = 0;
	out = (int *)malloc(sizeof(int) * length);
	if (out == NULL)
		return (0);
	while (i < length)
	{
		out[i] = f(tab[i]);
		i++;
	}
	return (out);
}
