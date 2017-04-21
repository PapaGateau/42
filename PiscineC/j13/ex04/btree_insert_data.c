/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:41:51 by plogan            #+#    #+#             */
/*   Updated: 2017/03/30 16:42:00 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)
		(void *, void *))
{
	t_btree	*node;

	if (!root || !cmpf)
		return ;
	if ((*root) == NULL)
	{
		node = btree_create_node(item);
		*root = node;
	}
	else if (cmpf((*root)->item, item) > 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else if (cmpf((*root)->item, item) <= 0)
		btree_insert_data(&(*root)->right, item, cmpf);
}
