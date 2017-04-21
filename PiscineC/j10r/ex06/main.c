/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:47:59 by plogan            #+#    #+#             */
/*   Updated: 2017/03/27 18:13:52 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int		check_nb(char *arg)
{
	int		i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (arg[i] > 57 || arg[i] < 48)
		return (0);
	return (1);
}

int		ft_calc(int n1, char *op, int n2)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (g_opptab[i].op == op[0])
			return (g_opptab[i].ft(n1, n2));
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	if (argv[2][1] == '\0')
	{
		ft_putnbr(ft_calc(ft_atoi(argv[1]), argv[2], ft_atoi(argv[3])));
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
