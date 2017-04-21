/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:49:14 by plogan            #+#    #+#             */
/*   Updated: 2017/03/23 14:03:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		size1;
	int		size2;

	size1 = 0;
	size2 = 0;
	while (dest[size1] != '\0')
	{
		size1++;
	}
	while (src[size2] != '\0')
	{
		dest[size1 + size2] = src[size2];
		size2++;
	}
	dest[size1 + size2] = '\0';
	return (dest);
}
