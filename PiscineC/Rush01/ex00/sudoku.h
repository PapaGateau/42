/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 20:47:28 by plogan            #+#    #+#             */
/*   Updated: 2017/03/19 21:12:44 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>

struct	s_position
{
	int	row;
	int	col;
};

void	ft_putchar(char c);
void	ft_propagate(int grid[9][9], int possibilities[9][9][10],
struct s_position position, int action);
void	ft_initial_propagation(int grid[9][9], int possibilities[9][9][10]);
void	ft_find_min(int grid[9][9], int possibilities[9][9][10],
int *row, int *col);
void	ft_print_grid(int grid[9][9]);
void	ft_error(void);
int		ft_input_grid(char **argv, int grid[9][9]);
void	ft_initialize_possibilities(int grid[9][9], int possibilities[9][9][10])
;
void	ft_resolve(int grid[9][9], int possibilities[9][9][10]);

#endif
