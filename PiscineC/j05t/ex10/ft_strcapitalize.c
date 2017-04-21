/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:12:26 by plogan            #+#    #+#             */
/*   Updated: 2017/03/14 15:58:53 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_min(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

int		is_maj(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

int		is_alphanum(char c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	if (str[0] >= 97 && str[0] <= 122)
	{
		str[0] = str[0] - 32;
	}
	while (str[i] != '\0')
	{
		if ((is_alphanum(str[i - 1]) == 0) && (is_min(str[i])))
		{
			str[i] = str[i] - 32;
		}
		if (is_alphanum(str[i - 1]) && (is_maj(str[i])))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
