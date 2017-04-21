/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:27:54 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 12:34:21 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*point;
	unsigned int	i;

	i = 0;
	point = begin_list;
	if (point)
	{
		while (i < nbr)
		{
			point = point->next;
			i++;
		}
	}
	return (point);
}
