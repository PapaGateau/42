/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:44:07 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 12:55:10 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*point;
	t_list	*temp;
	t_list	*temp2;

	point = *begin_list;
	if (!point || !(point->next))
		return ;
	temp = point->next;
	temp2 = temp->next;
	point->next = NULL;
	temp->next = point;
	while (temp2)
	{
		point = temp;
		temp = temp2;
		temp2 = temp2->next;
		temp->next = point;
	}
	*begin_list = temp;
}
