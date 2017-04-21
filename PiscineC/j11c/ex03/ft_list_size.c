/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 20:16:19 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 16:17:58 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*point;
	int		count;

	count = 0;
	point = begin_list;
	while (point)
	{
		point = point->next;
		count++;
	}
	return (count);
}
