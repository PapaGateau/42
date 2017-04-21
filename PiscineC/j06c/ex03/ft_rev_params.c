/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 07:46:01 by plogan            #+#    #+#             */
/*   Updated: 2017/03/22 10:48:13 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = argc;
	while (i - 1 > 0)
	{
		j = 0;
		while (argv[i - 1][j] != '\0')
		{
			ft_putchar(argv[i - 1][j]);
			j++;
		}
		ft_putchar('\n');
		i--;
	}
	return (0);
}
