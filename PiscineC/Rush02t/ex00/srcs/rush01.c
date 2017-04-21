/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 09:56:42 by phanna            #+#    #+#             */
/*   Updated: 2017/03/26 22:46:36 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*ft_strnew(int n)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (n + 1));
	if (s == NULL)
		return (0);
	while (i < n)
		s[i++] = 0;
	return (s);
}

static char	*rush_line(char c_begin, char c_between, char c_end, int large)
{
	int		i;
	char	*string;

	i = 0;
	if ((string = (char *)malloc(sizeof(char) * ((large + 1) + 1))) == NULL)
		return (0);
	while (i < large)
	{
		if (i == 0)
			string[i] = c_begin;
		else if (i == large - 1)
			string[i] = c_end;
		else
			string[i] = c_between;
		i++;
	}
	string[i++] = '\n';
	string[i] = '\0';
	return (string);
}

char		*rush01(int x, int y)
{
	int		inc_y;
	char	*string;

	string = ft_strnew((((x + 1) * y) + 1));
	inc_y = 0;
	while (inc_y < y)
	{
		if (inc_y == 0)
			string = ft_strcat(string, rush_line('/', '*', '\\', x));
		else if (inc_y == y - 1)
			string = ft_strcat(string, rush_line('\\', '*', '/', x));
		else
			string = ft_strcat(string, rush_line('*', ' ', '*', x));
		inc_y++;
	}
	string[(((x + 1) * y) + 1)] = '\0';
	return (string);
}
