/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:24:21 by plogan            #+#    #+#             */
/*   Updated: 2017/03/25 18:04:30 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_usage(int n1, int n2)
{
	n1++;
	n2++;
	write(1, "error : only [ + - * / % ] are accepted.\n", 41);
	return (0);
}
