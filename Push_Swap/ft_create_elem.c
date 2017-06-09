/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:11:53 by plogan            #+#    #+#             */
/*   Updated: 2017/06/07 14:45:25 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_create_elem(int data)
{
	t_stack	*new;

	if (!(new = malloc(sizeof(t_stack))))
		return (new);
	new->data = data;
	new->next = NULL;
	return (new);
}
