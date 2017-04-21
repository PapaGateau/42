/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 13:52:57 by plogan            #+#    #+#             */
/*   Updated: 2017/03/22 16:11:24 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_copy(char *str)
{
	int		j;
	char	*copy;

	j = 0;
	copy = (char*)malloc(sizeof(char) * (ft_len(str) + 1));
	if (copy == NULL)
		return (0);
	while (str[j] != '\0')
	{
		copy[j] = str[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*stab;
	int				i;

	i = 0;
	stab = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	if (stab == NULL)
		return (0);
	while (i < ac)
	{
		stab[i].size_param = ft_len(av[i]);
		stab[i].str = av[i];
		stab[i].copy = ft_copy(av[i]);
		stab[i].tab = ft_split_whitespaces(stab[i].copy);
		i++;
	}
	stab[i].str = 0;
	return (stab);
}
