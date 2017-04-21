/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:44:14 by plogan            #+#    #+#             */
/*   Updated: 2017/03/29 19:44:32 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(char c, int std)
{
	write(std, &c, 1);
}

void	ft_putstr(char *str, int std)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], std);
}

void	was_too_big(int ret, int argc, char **argv)
{
	char	temp[1];
	int		fd;

	if (argc == 1)
		ft_putstr("File name missing.\n", 2);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return ;
		while (ret > 0)
		{
			ret = read(fd, temp, 1);
			if (ret == -1)
				return ;
			if (ret > 0)
				ft_putchar(temp[0], 1);
		}
		ret = close(fd);
		if (ret == -1)
			return ;
	}
	else
		ft_putstr("Too many arguments.\n", 2);
	return ;
}

int		main(int argc, char **argv)
{
	int		ret;

	ret = 1;
	was_too_big(ret, argc, argv);
	return (0);
}
