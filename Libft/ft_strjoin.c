/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 10:47:41 by plogan            #+#    #+#             */
/*   Updated: 2017/04/14 13:27:07 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size1;
	int		size2;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	size1 = 0;
	size2 = 0;
	while (s1[size1])
		size1++;
	while (s2[size2])
		size2++;
	if (!(new = (char *)malloc(sizeof(new) * (size1 + size2) + 1)))
		return (NULL);
	while (i < size1)
		new[i++] = s1[j++];
	j = 0;
	while (i < size1 + size2)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
