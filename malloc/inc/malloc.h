/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:18:37 by plogan            #+#    #+#             */
/*   Updated: 2019/05/27 13:50:56 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/resource.h>
# include <sys/mman.h>
# include <unistd.h>

# define TINY_MAX_BLOCK_SIZE 1024
# define TINY_RANGE_SIZE (50 * getpagesize())

# define SMALL_MAX_BLOCK_SIZE 1024 * 10
# define SMALL_RANGE_SIZE (500 * getpagesize())

typedef enum			e_bool
{
	false,
	true
}						t_bool;

typedef enum			e_range_type
{
	TINY,
	SMALL,
	LARGE
}						t_range_type;

typedef struct			s_block
{
	t_bool				freed;
	size_t				size;
	struct s_block		*next;
}						t_block;

typedef struct			s_range
{
	enum e_range_type	type;
	size_t				space;
	struct s_range		*next;
}						t_range;

void					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
void					free(void *ptr);
t_range					**get_first_range(void);
t_block					*init_block(t_range *range, size_t block_size);
t_block					*check_free_blocks(int type, size_t size);
t_block					*split_block(t_block *block, size_t size);
void					print_str(char *str);
void					print_nbr_base(unsigned long nb, int base_size,
						int mode);
void					show_alloc_mem(void);

#endif
