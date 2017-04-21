/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:14:50 by plogan            #+#    #+#             */
/*   Updated: 2017/03/11 20:43:57 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		a;
	int		size;
	int		start;
	int		end;
	char	temp;

	a = 0;
	start = 0;
	size = 0;
	while (*(str + a) != '\0')
	{
		a++;
		size++;
	}
	end = size;
	while (end > start)
	{
		temp = *(str + start);
		*(str + start) = *(str + end - 1);
		*(str + end - 1) = temp;
		start++;
		end--;
	}
	return (str);
}
