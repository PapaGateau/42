/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:43:38 by plogan            #+#    #+#             */
/*   Updated: 2017/03/22 15:31:27 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (1);
	else
		return (0);
}

int		ft_size(char *str)
{
	int		s;

	s = 0;
	while (str[s] && is_whitespace(str[s]) == 0)
		s++;
	return (s);
}

int		ft_count_str(char *str)
{
	int		n;
	int		count;

	n = 0;
	count = 0;
	while (str[n])
	{
		if (is_whitespace(str[n]) == 0 && (is_whitespace(str[n - 1]) || n == 0))
			count++;
		n++;
	}
	return (count);
}

char	**ft_assign(char **tab, int i, int j, char *str)
{
	int		k;

	k = 0;
	while (str[k])
	{
		j = 0;
		if (is_whitespace(str[k]) == 0 && (is_whitespace(str[k - 1]) || k == 0))
		{
			tab[i] = (char*)malloc(sizeof(char) * (ft_size(&str[k]) + 1));
			if (tab[i] == NULL)
				return (0);
			while (str[k] && is_whitespace(str[k]) == 0)
			{
				tab[i][j++] = str[k++];
			}
			tab[i++][j] = '\0';
		}
		k++;
	}
	return (tab);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		return (0);
	tab = (char**)malloc(sizeof(char *) * (ft_count_str(str) + 1));
	if (tab == NULL)
		return (0);
	ft_assign(tab, i, j, str);
	tab[ft_count_str(str)] = 0;
	return (tab);
}
