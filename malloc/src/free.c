/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:36:27 by plogan            #+#    #+#             */
/*   Updated: 2019/04/23 15:33:35 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

void	check_for_munmap(t_range *range)
{
	t_block	*block;
	t_range	*temp;

	temp = *get_first_range();
	while (temp->next && temp->next != range)
		temp = temp->next;
	block = (t_block *)((char *)range + sizeof(t_range));
	if (block->freed && !block->next)
	{
		if (*get_first_range() == range)
			*get_first_range() = range->next;
		else
			temp->next = range->next;
		if (range->type == TINY)
			munmap(range, TINY_RANGE_SIZE);
		else if (range->type == SMALL)
			munmap(range, SMALL_RANGE_SIZE);
		else
			munmap(range, block->size + sizeof(t_block) + sizeof(t_range));
	}
}

void	check_for_merge(t_range *range)
{
	t_block *alpha_block;
	t_block *beta_block;

	alpha_block = (t_block *)((char *)range + sizeof(t_range));
	while (alpha_block && alpha_block->next)
	{
		beta_block = alpha_block->next;
		if (beta_block->freed && alpha_block->freed)
		{
			while (beta_block && beta_block->freed)
			{
				alpha_block->size += beta_block->size + sizeof(t_block);
				alpha_block->next = beta_block->next;
				beta_block = beta_block->next;
			}
		}
		alpha_block = alpha_block->next;
	}
}

void	free(void *ptr)
{
	t_range *range;
	t_block *block;

	if (!ptr || !(range = *get_first_range()))
		return ;
	while (range)
	{
		block = (t_block *)((char *)range + sizeof(t_range));
		while (block)
		{
			if ((void *)block + sizeof(t_block) == ptr)
			{
				block->freed = 1;
				if (range->type != LARGE)
					check_for_merge(range);
				check_for_munmap(range);
				return ;
			}
			block = block->next;
		}
		range = range->next;
	}
}
