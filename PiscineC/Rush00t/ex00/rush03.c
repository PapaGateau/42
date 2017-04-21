/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberrido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 23:16:41 by tberrido          #+#    #+#             */
/*   Updated: 2017/03/12 21:54:32 by tberrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

void		ft_select_char(int x, int i_x, int y, int i_y)
{
	if ((i_y == 0) || (i_y == y))
	{
		if (i_x == 0)
			ft_putchar('A');
		if (i_x == x)
			ft_putchar('C');
		if (i_x < (x - 1))
			ft_putchar('B');
	}
	else
	{
		if ((i_x == 0) || (i_x == x))
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
	}
}

void		rush(int x, int y)
{
	int i_x;
	int i_y;

	i_y = 0;
	while (i_y < y)
	{
		i_x = 0;
		while (i_x < x)
		{
			ft_select_char(x - 1, i_x, y - 1, i_y);
			i_x++;
		}
		ft_putchar('\n');
		i_y++;
	}
}
