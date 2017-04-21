/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:59:19 by plogan            #+#    #+#             */
/*   Updated: 2017/03/29 20:01:08 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putchar(char c, int s)
{
	write(s, &c, 1);
}

void	ft_putstr(char *str, int s)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], s);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
