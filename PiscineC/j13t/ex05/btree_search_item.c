/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:46:13 by plogan            #+#    #+#             */
/*   Updated: 2017/03/30 16:35:29 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *,
			void *))
{
	void	*result;

	result = 0;
	if (root)
	{
		if (root->left)
			result = btree_search_item(root->left, data_ref, cmpf);
		if (!result)
		{
			result = ((cmpf(data_ref, root->item) == 0) ? root->item : 0);
		}
		if (root->right && !result)
			result = btree_search_item(root->right, data_ref, cmpf);
	}
	return (result);
}
