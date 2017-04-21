/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:06:19 by plogan            #+#    #+#             */
/*   Updated: 2017/03/29 21:09:29 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_buffer(char *dest, char *input)
{
	int		i;
	int		j;
	char	*buffer;
	int		length;

	i = 0;
	j = 0;
	length = ft_strlen(dest) + ft_strlen(input);
	if ((buffer = (char *)malloc(sizeof(char) * (length + 1))) == NULL)
		return (NULL);
	buffer[length] = 0;
	while (dest[i])
	{
		buffer[i] = dest[i];
		i++;
	}
	while (input[j])
		buffer[i++] = input[j++];
	buffer[i] = 0;
	free(dest);
	return (buffer);
}
