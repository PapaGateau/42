/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_possibilities.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 21:15:12 by fbonnin           #+#    #+#             */
/*   Updated: 2017/03/19 21:00:34 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_initialize_possibilities(int grid[9][9], int possibilities[9][9][10])
{
	int row;
	int col;
	int content;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			content = 1;
			while (content < 10)
			{
				possibilities[row][col][content] = 0;
				content++;
			}
			col++;
		}
		row++;
	}
	ft_initial_propagation(grid, possibilities);
}

void	ft_initial_propagation(int grid[9][9], int possibilities[9][9][10])
{
	int					row;
	int					col;
	struct s_position	position;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			if (grid[row][col] != 0)
			{
				position.row = row;
				position.col = col;
				ft_propagate(grid, possibilities, position, 0);
			}
			col++;
		}
		row++;
	}
}
