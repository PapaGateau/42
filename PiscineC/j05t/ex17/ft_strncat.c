/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:09:11 by plogan            #+#    #+#             */
/*   Updated: 2017/03/14 17:21:05 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		size1;
	int		size2;

	size1 = 0;
	size2 = 0;
	while (dest[size1] != '\0')
	{
		size1++;
	}
	while (src[size2] != '\0' && size2 < nb)
	{
		dest[size1 + size2] = src[size2];
		size2++;
	}
	dest[size1 + size2] = '\0';
	return (dest);
}
