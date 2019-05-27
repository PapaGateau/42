/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:51:30 by plogan            #+#    #+#             */
/*   Updated: 2019/04/25 16:53:38 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/malloc.h"

t_range		**get_first_range(void)
{
	static t_range	*range = NULL;

	return (&range);
}

t_range		*make_new_range(int type, size_t range_size, t_range *next)
{
	t_range *new;

	if (!(new = (t_range *)mmap(0, range_size, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (new);
	new->type = type;
	new->space = range_size - sizeof(t_range);
	new->next = next;
	return (new);
}

t_range		*check_range_space(int type, size_t size)
{
	t_range	*temp;

	temp = *get_first_range();
	while (temp)
	{
		if (temp->type == type && temp->space >= (size + sizeof(t_block)))
			return (temp);
		temp = temp->next;
	}
	return (temp);
}

t_block		*block_handler(size_t size, int type, size_t range_size)
{
	t_range	*temp;
	t_block	*block;

	block = NULL;
	temp = NULL;
	if (!*get_first_range())
	{
		*get_first_range() = make_new_range(type, range_size, NULL);
		return (init_block(*get_first_range(), size));
	}
	else if (type != LARGE && (block = check_free_blocks(type, size)))
		return (split_block(block, size));
	else if (type != LARGE && (temp = check_range_space(type, size)))
		return (init_block(temp, size));
	else
	{
		temp = *get_first_range();
		while (temp->next)
			temp = temp->next;
		temp->next = make_new_range(type, range_size, NULL);
		return (init_block(temp->next, size));
	}
}

void		*malloc(size_t size)
{
	struct rlimit	rlp;
	t_block			*block;

	getrlimit(RLIMIT_DATA, &rlp);
	if (size == 0 || (size + sizeof(t_range) + sizeof(t_block)) < size ||
			(rlp.rlim_cur - sizeof(t_range) - sizeof(t_block)) < size)
		return (NULL);
	if (size <= TINY_MAX_BLOCK_SIZE)
		block = block_handler(size, TINY, TINY_RANGE_SIZE);
	else if (size <= SMALL_MAX_BLOCK_SIZE)
		block = block_handler(size, SMALL, SMALL_RANGE_SIZE);
	else
		block = block_handler(size, LARGE, size + sizeof(t_range) +
				sizeof(t_block));
	return ((void *)((char *)block + sizeof(t_block)));
}
