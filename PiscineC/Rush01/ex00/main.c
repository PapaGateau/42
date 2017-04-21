/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:46:49 by fbonnin           #+#    #+#             */
/*   Updated: 2017/03/19 21:08:15 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int argc, char **argv)
{
	int grid[9][9];
	int possibilities[9][9][10];

	if (argc != 10)
	{
		ft_error();
		return (0);
	}
	if (ft_input_grid(argv, grid) != 0)
	{
		ft_error();
		return (0);
	}
	ft_initialize_possibilities(grid, possibilities);
	ft_resolve(grid, possibilities);
	return (0);
}
