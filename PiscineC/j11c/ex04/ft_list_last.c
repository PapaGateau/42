/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 20:51:00 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 16:19:55 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*point;

	point = begin_list;
	if (point)
	{
		while (point->next != NULL)
		{
			point = point->next;
		}
		return (point);
	}
	return (point);
}
