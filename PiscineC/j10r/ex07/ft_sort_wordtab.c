/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:21:09 by plogan            #+#    #+#             */
/*   Updated: 2017/03/27 17:16:04 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int		j;

	j = 0;
	while (s1[j] == s2[j] && s1[j] != '\0' && s2[j] != '\0')
	{
		j++;
	}
	return (s1[j] - s2[j]);
}

void	ft_sort_wordtab(char **tab)
{
	int		i;
	char	*t;

	i = 1;
	while (tab[i] != 0)
	{
		if (ft_strcmp(tab[i - 1], tab[i]) > 0)
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
