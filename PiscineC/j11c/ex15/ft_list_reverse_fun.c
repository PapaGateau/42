/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 11:04:27 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 21:59:59 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*point;
	t_list	*new;

	if (begin_list == NULL)
		return ;
	point = NULL;
	while (begin_list)
	{
		new = begin_list->next;
		begin_list->next = point;
		point = begin_list;
		begin_list = new;
	}
}
