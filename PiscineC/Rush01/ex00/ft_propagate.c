/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_propagate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pseck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:20:53 by pseck             #+#    #+#             */
/*   Updated: 2017/03/19 21:02:20 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_propagate_square(int grid[9][9], int possibilities[9][9][10],
struct s_position position, int action)
{
	int i;
	int j;
	int row;
	int col;
	int content;

	content = grid[position.row][position.col];
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			row = position.row - position.row % 3 + i;
			col = position.col - position.col % 3 + j;
			if (grid[row][col] == 0)
				possibilities[row][col][content] +=
					(action == 0 ? 1 : -1);
			j++;
		}
		i++;
	}
}

void	ft_propagate(int grid[9][9], int possibilities[9][9][10],
struct s_position position, int action)
{
	int i;
	int j;
	int content;

	content = grid[position.row][position.col];
	i = 0;
	while (i < 9)
	{
		if (grid[i][position.col] == 0)
			possibilities[i][position.col][content] +=
				(action == 0 ? 1 : -1);
		i++;
	}
	j = 0;
	while (j < 9)
	{
		if (grid[position.row][j] == 0)
			possibilities[position.row][j][content] +=
				(action == 0 ? 1 : -1);
		j++;
	}
	ft_propagate_square(grid, possibilities, position, action);
}
