/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:32:53 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 12:53:25 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*point;

	point = begin_list;
	while (point != NULL)
	{
		if ((*cmp)(point->data, data_ref) == 0)
			return (point);
		point = point->next;
	}
	return (0);
}
