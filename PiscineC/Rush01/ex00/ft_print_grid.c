/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:49:47 by fbonnin           #+#    #+#             */
/*   Updated: 2017/03/19 21:01:42 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_print_grid(int grid[9][9])
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
			content = grid[row][col];
			if (content == 0)
				ft_putchar('.');
			else
				ft_putchar(content + 48);
			if (col < 8)
				ft_putchar(' ');
			else
				ft_putchar('\n');
			col++;
		}
		row++;
	}
}
