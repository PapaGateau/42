/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 21:35:22 by plogan            #+#    #+#             */
/*   Updated: 2017/03/28 22:21:08 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_push(t_list **begin_list, void *data)
{
	t_list	*new_node;

	if (begin_list == NULL)
		return ;
	new_node = ft_create_elem(data);
	if (*begin_list == NULL)
	{
		*begin_list = new_node;
		(*begin_list)->next = NULL;
		return ;
	}
	new_node->next = *begin_list;
	*begin_list = new_node;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*point;

	if (ac == 0)
		return (0);
	point = ft_create_elem(av[0]);
	i = 1;
	while (i < ac)
	{
		ft_push(&point, av[i]);
		i++;
	}
	return (point);
}
