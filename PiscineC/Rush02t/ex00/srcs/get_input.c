/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 13:54:41 by gduron            #+#    #+#             */
/*   Updated: 2017/03/26 22:44:22 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_input(void)
{
	char	*dest;
	char	*buff;
	int		ret;
	int		i;

	i = 1;
	if ((dest = (char *)malloc(sizeof(char) * 1)) == NULL)
		return (0);
	dest[0] = '\0';
	if ((buff = (char *)malloc(sizeof(char) * (4096 + 1))) == NULL)
		return (0);
	while ((ret = read(0, buff, 4096 * i)) > 0)
	{
		buff[ret] = '\0';
		dest = ft_strjoin(dest, buff);
		if ((buff = (char *)malloc(sizeof(char) * (4096 * i + 1))) == NULL)
			return (0);
		i++;
	}
	free(buff);
	return (dest);
}
