/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:42:01 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 21:59:32 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*first;
	t_list	*second;
	t_list	*temp;

	if (begin_list == NULL)
		return ;
	if (*begin_list == NULL)
		return ;
	temp = NULL;
	first = *begin_list;
	second = (*begin_list)->next;
	while (second->next != NULL)
	{
		if ((*cmp)(first->data, second->data) > 0)
		{
			temp = first;
			first->data = second->data;
			second->data = temp->data;
		}
		first = first->next;
		second = second->next;
	}
}
