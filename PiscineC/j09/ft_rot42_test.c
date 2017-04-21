/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 05:32:41 by plogan            #+#    #+#             */
/*   Updated: 2017/03/17 06:04:04 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_rot42(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 97) && (str[i] <= 122))
		{
			if (str[i] < 'k')
				str[i] = str[i] + 16;
			else if (str[i] >= 'k')
				str[i] = str[i] - 10;
		}
		else if ((str[i] >= 65) && (str[i] <= 90))
		{
			if (str[i] < 'K')
				str[i] = str[i] + 16;
			else if (str[i] >= 'K')
				str[i] = str[i] - 10;
		}
		i++;
	}
	return (str);
}

int		main(void)
{
	char	str[] = "123abc123ABC";

	ft_rot42(str);
	printf("%s", str);
	return (0);
}
