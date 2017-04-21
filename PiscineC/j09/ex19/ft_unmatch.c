/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:00:53 by plogan            #+#    #+#             */
/*   Updated: 2017/03/17 14:31:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	while (i < length)
	{
		j = 0;
		found = 1;
		while (j < length)
		{
			if (j != i && tab[i] == tab[j])
			{
				found = 0;
				break ;
			}
			j++;
		}
		if (found == 1)
		{
			return (tab[i]);
		}
		i++;
	}
	return (0);
}
