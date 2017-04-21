/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:59:25 by plogan            #+#    #+#             */
/*   Updated: 2017/03/29 12:12:59 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_base(char *base)
{
	int		base_size;
	int		check_repeat;

	base_size = 0;
	while (base[base_size] != '\0')
	{
		if ((base[base_size] < 32) || (base[base_size] > 126))
			return (0);
		if ((base[base_size] == '-') || (base[base_size] == '+'))
			return (0);
		check_repeat = 0;
		while (base[check_repeat] != '\0')
		{
			if ((base[check_repeat] == base[base_size])
				&& (base_size != check_repeat))
				return (0);
			check_repeat++;
		}
		base_size++;
	}
	if (base_size <= 1)
		return (0);
	return (1);
}

void	print_nbr(int nbr, int base_size, char *base)
{
	int		i;

	i = 0;
	if ((nbr != 0) && (nbr >= base_size))
	{
		print_nbr((nbr / base_size), base_size, base);
	}
	i = nbr % base_size;
	ft_putchar(base[i]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;

	base_size = 0;
	if (check_base(base))
	{
		while (base[base_size])
		{
			base_size++;
		}
		print_nbr(nbr, base_size, base);
	}
}

int		main(void)
{
	int		nb = 6;
	char	base[] = "01";

	ft_putnbr_base(nb, base);
	return (0);
}
