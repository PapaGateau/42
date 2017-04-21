/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:46:03 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 20:04:38 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*previous;

	while (begin_list != NULL)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
		{
			if (previous == NULL)
				previous = begin_list->next;
			else
				previous->next = begin_list->next;
			free(begin_list);
		}
		previous = begin_list;
		begin_list = begin_list->next;
	}
}
