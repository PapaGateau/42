/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:50:14 by plogan            #+#    #+#             */
/*   Updated: 2017/03/26 23:34:55 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		get_x(char *str)
{
	int		x;

	x = 0;
	while (str[x] != '\n' && str[x])
		x++;
	return (x);
}

int		get_y(char *str)
{
	int		y;
	int		index;

	y = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
			y++;
		index++;
	}
	return (y);
}

void	print_colle(int *pipe, int colle, int x, int y)
{
	if (colle == -1 && *pipe < 1)
	{
		ft_putstr("aucune");
		return ;
	}
	if (colle != -1)
	{
		if (*pipe == 1)
			ft_putstr(" || ");
		ft_putstr("[colle-0");
		ft_putnbr(colle);
		ft_putstr("] [");
		ft_putnbr(x);
		ft_putstr("] [");
		ft_putnbr(y);
		ft_putstr("]");
		*pipe = 1;
	}
}

void	check_colle(char *str, int x, int y)
{
	int		pipe;

	pipe = 0;
	if (!ft_strcmp(str, rush00(x, y)))
		print_colle(&pipe, 0, x, y);
	if (!ft_strcmp(str, rush01(x, y)))
		print_colle(&pipe, 1, x, y);
	if (!ft_strcmp(str, rush02(x, y)))
		print_colle(&pipe, 2, x, y);
	if (!ft_strcmp(str, rush03(x, y)))
		print_colle(&pipe, 3, x, y);
	if (!ft_strcmp(str, rush04(x, y)))
		print_colle(&pipe, 4, x, y);
	print_colle(&pipe, -1, 0, 0);
}

void	find_colle(char *str)
{
	int		x;
	int		y;

	x = get_x(str);
	y = get_y(str);
	check_colle(str, x, y);
	ft_putstr("\n");
}
