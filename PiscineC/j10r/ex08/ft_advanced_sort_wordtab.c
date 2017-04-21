/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 10:46:08 by plogan            #+#    #+#             */
/*   Updated: 2017/03/24 10:49:25 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*t;

	i = 1;
	while (tab[i] != 0)
	{
		if (cmp(tab[i - 1], tab[i]) > 0)
		{
			t = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = t;
			i = 1;
		}
		else
			i++;
	}
}
