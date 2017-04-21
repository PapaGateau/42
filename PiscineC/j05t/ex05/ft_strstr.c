/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:38:33 by plogan            #+#    #+#             */
/*   Updated: 2017/03/13 18:37:23 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (to_find[size] != '\0')
	{
		size++;
	}
	if (size == 0)
		return (str);
	while (str[i] == to_find[0] || str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (str[i + j] == to_find[size - 1])
				return (str + i);
		}
		i++;
	}
	return (0);
}
