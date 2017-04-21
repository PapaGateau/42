/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberrido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 23:16:41 by tberrido          #+#    #+#             */
/*   Updated: 2017/03/11 16:08:22 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

void		ft_select_char(int x, int i_x, int y, int i_y)
{
	if ((i_x > 0 && i_x < x) || (i_y > 0 && i_y < y))
	{
		if (i_x == 0 || i_y == 0 || i_x == x || i_y == y)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
	}
	else
	{
		if (i_y == 0)
		{
			ft_putchar('A');
		}
		else
		{
			ft_putchar('C');
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
