/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonnin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:04:03 by fbonnin           #+#    #+#             */
/*   Updated: 2017/03/19 15:22:10 by fbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_input_grid(char **argv, int grid[9][9])
{
	int		row;
	int		col;
	char	content;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			content = argv[1 + row][col];
			if (content == '\0')
				return (-1);
			if (content == '.')
				grid[row][col] = 0;
			else if (content >= '1' && content <= '9')
				grid[row][col] = content - 48;
			else
				return (-1);
			col++;
		}
		row++;
	}
	return (0);
}
