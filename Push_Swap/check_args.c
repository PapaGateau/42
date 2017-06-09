/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:55:15 by plogan            #+#    #+#             */
/*   Updated: 2017/06/07 18:37:12 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_str(char *arg)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(arg);
	if (size == 0)
		return (0);
	if (ft_atoi(arg) > INT_MAX || ft_atoi(arg) < INT_MIN)
		return (0);
	while (i < size)
	{
		if (arg[i] != '+' && arg[i] != '-' && !isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int			check_args(int argc, char **argv)
{
	int		arg_i;
	int		cmp_index;

	arg_i = 1;
	while (arg_i < argc)
	{
		if (!check_str(argv[arg_i]))
			return (0);
		cmp_index = 1;
		while (cmp_index < argc)
		{
			if (arg_i == cmp_index)
				cmp_index++;
			if (arg_i < argc - 1 && !ft_strcmp(argv[arg_i], argv[cmp_index]))
				return (0);
			cmp_index++;
		}
		arg_i++;
	}
	return (1);
}
