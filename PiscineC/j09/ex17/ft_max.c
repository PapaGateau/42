/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:51:11 by plogan            #+#    #+#             */
/*   Updated: 2017/03/17 13:55:14 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *tab, int length)
{
	int		index1;
	int		index2;

	index1 = 1;
	index2 = tab[0];
	while (index1 < length)
	{
		if (index2 < tab[index1])
		{
			index2 = tab[index1];
		}
		index1++;
	}
	return (index2);
}
