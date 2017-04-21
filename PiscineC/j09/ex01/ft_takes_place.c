/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 02:50:29 by plogan            #+#    #+#             */
/*   Updated: 2017/03/17 04:05:30 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_noon(int hour)
{
	if (hour == 12)
		printf("%s", "12.00 P.M. AND 1.00 P.M.\n");
	else
		printf("%s", "12.00 A.M. AND 1.00 A.M.\n");
}

void	ft_elam(int hour)
{
	if (hour == 11)
		printf("%s", "11.00 A.M. AND 12.00 P.M.\n");
	else
		printf("%s", "11.00 P.M. AND 12.00 A.M.\n");
}

void	ft_pm(int hour1, int hour2)
{
	printf("%d", hour1);
	printf("%s", ".00 P.M. AND ");
	printf("%d", hour2);
	printf("%s", ".00 P.M.\n");
}

void	ft_am(int hour)
{
	int		hour1;
	int		hour2;

	hour1 = hour;
	hour2 = hour1 + 1;
	if (hour == 0)
		printf("%s", "12.00 A.M. AND 1.00 A.M.\n");
	else
	{
		hour1 = hour;
		printf("%d", hour1);
		printf("%s", ".00 A.M. AND ");
		hour2 = hour1 + 1;
		printf("%d", hour2);
		printf("%s", ".00 A.M.\n");
	}
}

void	ft_takes_place(int hour)
{
	int		hour1;
	int		hour2;

	hour1 = 0;
	hour2 = 0;
	printf("%s", "THE FOLLOWING TAKES PLACE BETWEEN ");
	if (hour == 12 || hour == 24)
		ft_noon(hour);
	if (hour == 11 || hour == 23)
		ft_elam(hour);
	if (hour > 12 && hour < 23)
	{
		hour1 = hour - 12;
		hour2 = hour1 + 1;
		ft_pm(hour1, hour2);
	}
	if (hour < 11)
		ft_am(hour);
}
