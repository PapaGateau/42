/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:16:52 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 22:22:20 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*point;
	t_list	*remove;

	if (begin_list == NULL)
		return ;
	if (*begin_list == NULL)
		return ;
	point = *begin_list;
	while (point->next != NULL)
	{
		remove = point;
		point = point->next;
		free(remove);
	}
	free(point);
	*begin_list = NULL;
}
