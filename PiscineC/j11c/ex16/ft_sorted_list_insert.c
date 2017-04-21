/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:04:25 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 22:00:53 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*first;
	t_list	*second;
	t_list	*new;

	if (begin_list == NULL)
		return ;
	if (*begin_list == NULL)
		return ;
	first = *begin_list;
	second = (*begin_list)->next;
	while (second != NULL)
	{
		if ((*cmp)(data, second->data) > 0)
		{
			new = ft_create_elem(data);
			first->next = new;
			new->next = second;
		}
		second = second->next;
		first = first->next;
	}
}
