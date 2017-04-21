/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:10:14 by gduron            #+#    #+#             */
/*   Updated: 2017/03/26 22:34:12 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strjoin(char *dest, char *new)
{
	int		total_len;
	char	*tmp;
	int		i;

	i = 0;
	total_len = ft_strlen(dest) + ft_strlen(new);
	if ((tmp = (char *)malloc(sizeof(char) * (total_len + 1))) == NULL)
		return (0);
	tmp[total_len] = '\0';
	while (dest[i])
	{
		tmp[i] = dest[i];
		i++;
	}
	while (*new)
	{
		tmp[i++] = *new++;
	}
	tmp[i] = '\0';
	free(dest);
	return (tmp);
}
