/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pseck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:48:39 by pseck             #+#    #+#             */
/*   Updated: 2017/03/19 20:56:39 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nb_possibilities(int possibilities[9][9][10], int i, int j)
{
	int nb_possibilities;
	int k;

	nb_possibilities = 0;
	k = 1;
	while (k < 10)
	{
		if (possibilities[i][j][k] == 0)
			nb_possibilities++;
		k++;
	}
	return (nb_possibilities);
}

int		ft_update_min(int *min_nb_possibilities, int nb_possibilities)
{
	if (nb_possibilities < *min_nb_possibilities)
	{
		*min_nb_possibilities = nb_possibilities;
		return (1);
	}
	else
		return (0);
}

void	ft_update_position(int *row, int *col, int i, int j)
{
	*row = i;
	*col = j;
}

void	ft_find_min(int grid[9][9], int possibilities[9][9][10],
int *row, int *col)
{
	int min_nb_possibilities;
	int nb_possibilities;
	int i;
	int j;

	min_nb_possibilities = 1000;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grid[i][j] == 0)
			{
				nb_possibilities = ft_nb_possibilities(possibilities, i, j);
				if (ft_update_min(&min_nb_possibilities, nb_possibilities) == 1)
					ft_update_position(row, col, i, j);
			}
			j++;
		}
		i++;
	}
}
