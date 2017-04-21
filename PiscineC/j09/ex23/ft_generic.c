/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:45:06 by plogan            #+#    #+#             */
/*   Updated: 2017/03/17 15:57:21 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_tu(void)
{
	ft_putchar('T');
	ft_putchar('u');
	ft_putchar(' ');
	ft_putchar('t');
	ft_putchar('u');
	ft_putchar(' ');
	ft_putchar('t');
	ft_putchar('u');
	ft_putchar(' ');
	ft_putchar('t');
	ft_putchar('u');
}

void	ft_generic(void)
{
	ft_tu();
	ft_putchar(' ');
	ft_putchar(';');
	ft_putchar(' ');
	ft_tu();
	ft_putchar('\n');
}
