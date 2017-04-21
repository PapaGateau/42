/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:14:50 by plogan            #+#    #+#             */
/*   Updated: 2017/03/13 19:47:55 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		size;
	int		start;
	int		end;
	char	temp;

	start = 0;
	size = 0;
	while (*(str + size) != '\0')
	{
		size++;
	}
	while (end > start)
	{
		temp = *(str + start);
		*(str + start) = *(str + size - 1);
		*(str + size - 1) = temp;
		start++;
		size--;
	}
	return (str);
}

int		main(void)
{
	str [] = "bonjour";

	ft_strrev(&str);
	printf("%s", str);
}
