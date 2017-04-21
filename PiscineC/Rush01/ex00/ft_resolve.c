/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pseck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:04:04 by pseck             #+#    #+#             */
/*   Updated: 2017/03/19 21:04:48 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_resolved(int grid[9][9])
{
	int row;
	int col;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			if (grid[row][col] == 0)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

void	ft_resolve(int grid[9][9], int possibilities[9][9][10])
{
	int					row_min;
	int					col_min;
	struct s_position	position;
	int					content;

	if (ft_resolved(grid))
	{
		ft_print_grid(grid);
		return ;
	}
	ft_find_min(grid, possibilities, &row_min, &col_min);
	position.row = row_min;
	position.col = col_min;
	content = 1;
	while (content < 10)
	{
		if (possibilities[row_min][col_min][content++] == 0)
		{
			grid[row_min][col_min] = content - 1;
			ft_propagate(grid, possibilities, position, 0);
			ft_resolve(grid, possibilities);
			ft_propagate(grid, possibilities, position, 1);
			grid[row_min][col_min] = 0;
		}
	}
}
