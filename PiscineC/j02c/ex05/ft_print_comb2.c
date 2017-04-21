/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:52:01 by plogan            #+#    #+#             */
/*   Updated: 2017/03/09 16:57:49 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_convertchar(int n)
{
	int unit;
	int decimal;

	unit = n % 10;
	decimal = n / 10;
	ft_putchar(decimal + '0');
	ft_putchar(unit + '0');
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_convertchar(a);
			ft_putchar(' ');
			ft_convertchar(b);
			if (a == 98 && b == 99)
			{
				return ;
			}
			ft_putchar(',');
			ft_putchar(' ');
			b++;
		}
		a++;
	}
}
