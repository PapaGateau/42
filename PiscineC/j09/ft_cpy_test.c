/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 07:23:07 by plogan            #+#    #+#             */
/*   Updated: 2017/03/17 09:57:41 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_cmp(char arg, char str)
{
	if (arg == str || arg == str - 32)
		return (1);
	else
		return (0);
}

int		ft_strcmp(char *arg, char *str)	
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arg[i] == ' ')
		i++;
	while (str[j] != '\0')
	{
		if (ft_cmp(arg[i], str[j]) == 0)
			return (0);
		j++;
		i++;
	}
	while (arg[i] != '\0')
	{
		if (arg[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		check_argument(char *argv, int argc)
{
	int		i;
	char	*pres;
	char	*att;
	char	*pow;

	i = 0;
	pres = "president";
	att = "attack";
	pow = "powers";
	while (i < argc)
	{
		if (ft_strcmp(&argv[i], pres) || ft_strcmp(&argv[i], att) 
						|| (ft_strcmp(&argv[i], pow)))
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (check_argument(argv[i], argc - 1) > 0)
		{
			ft_putchar('A');
			ft_putchar('l');
			ft_putchar('e');
			ft_putchar('r');
			ft_putchar('t');
			ft_putchar('!');
			ft_putchar('!');
			ft_putchar('!');
			ft_putchar('\n');
			return (0);
		}
		i++;
	}	
	return (0);
}
